open Parser
open Char

(***********************
				MLVALUES
************************)
type mlvalue = Entier of int
						 | Fermeture of int * mlvalue
						 | Env of mlvalue list
						 | Bloc of mlvalue array

(************************
		REGISTRES Mini-ZAM
*************************)
let prog : triplet list ref = ref (parse Sys.argv.(1))(*liste des triplet d'instructions type = triplet list*)
let stack : mlvalue list ref = ref []  (*pile Last In First Out*)
let env : mlvalue ref = ref (Env([])) (*environnement courant*)
let pc = ref 0 (*pointeur sur la ligne courante*)
let accu = ref (Entier 0) (*registre temporaire de type mlvalue*)
let extra_args = ref 0
let trap_sp = ref (-1)

(*************************
			 AUXILIAIRES
**************************)
(* val get_int : mlvalue -> int *)
let get_int value =
	match value with
	| Entier i -> i
  | _ -> 0

(* val int_of_bool : bool -> int *)
let int_of_bool b =
	if b then 1 else 0

(* val depile : int -> mlvalue list *)
let rec depile n =
	match n with
		|x when x < 0 -> failwith "Argument de depile négatif"
		|0 -> []
		|_ -> let e = (List.hd !stack) in
			(stack:=(List.tl !stack);
			e::(depile (n-1)))

(* val get_pos_label : string -> Parser.triplet list -> int *)
let rec get_pos_label label list_record =
	match list_record with
	| {label=Some x;_}::tl when x=label -> 0
	| [] -> failwith "Le label demandé n'existe pas"
	| hd::tl -> 1 + get_pos_label label tl

(* val print_list_aux : mlvalue list -> unit *)
let rec print_list_aux l =
	(match l with
	| [] -> ()
	| hd::tl -> print_mlvalue hd;
							if tl==[] then print_list_aux tl
												else print_string ";";print_list_aux tl)

(* val print_mlvalue : mlvalue -> unit *)
and print_mlvalue m =
	match m with
	| Entier v -> print_int v
	| Fermeture(v,l)-> print_string "{";print_int v;print_string ",";print_mlvalue l;print_string"}"
	| Env(l) -> print_string"[";print_list_aux l;print_string"]"
	| Bloc a -> let l = Array.to_list a in print_string "(";print_mlvalue (List.hd l);print_string ","; print_list_aux (List.tl l);print_string ")"

(* val passe : Parser.triplet list -> Parser.triplet list *)
let passe prog =
	let res : triplet list ref = ref [] in
		let rec aux prog=
			(match prog with
				|[] -> !res
				|hd::tl -> (match hd with
										| {label;instr="APPLY";args} ->	let n = (int_of_string (List.hd args)) in
																											(match tl with
																											| {label;instr="RETURN";args}::tll-> let m = n+(int_of_string (List.hd args)) in res:=!res@{label=label; instr="APPTERM" ; args= string_of_int(n)::string_of_int(m)::[]}::[];
																																													 aux tll
																											| {label;instr;args}::tll-> res:=!res@hd::{label;instr;args}::[];
																																	 								aux tll
																											| _ -> failwith "pas possible")
										| {label;instr;args} -> res :=(!res)@{label=label; instr=instr; args=args}::[];
																						aux tl)
			)

		in aux prog


(**********************
 			OPERATIONS
***********************)
(* val const : mlvalue -> unit *)
let const n =
	accu := n;
	pc := !pc+1

(* val op_binaire : string -> unit *)
let op_binaire op =
	let stack_val = (get_int (List.hd !stack)) in
		let accu_val = (get_int !accu) in
			 (match op with
				|"+" -> accu := Entier (accu_val  + stack_val)
				|"-" -> accu := Entier (accu_val - stack_val)
				|"/" -> accu := Entier (accu_val / stack_val)
				|"*" -> accu := Entier (accu_val * stack_val)
				|"or" -> accu := Entier (if (accu_val==1 || stack_val==1) then 1 else 0)
				|"and" -> accu := Entier (if (accu_val==1 && stack_val==1) then 1 else 0)
				|"<>" -> accu := Entier (int_of_bool (accu_val <> stack_val))
				|"=" -> accu := Entier (int_of_bool (accu_val = stack_val))
				|"<" -> accu := Entier (int_of_bool (accu_val < stack_val))
				|"<=" -> accu := Entier (int_of_bool (accu_val <= stack_val))
				|">" -> accu := Entier (int_of_bool (accu_val >= stack_val))
				|">=" -> accu := Entier (int_of_bool (accu_val >= stack_val))
				| _ -> ());
			 stack := List.tl !stack;
			 pc:=!pc+1

(* val op_unaire : string -> unit *)
let op_unaire op =
	let accu_val = (get_int !accu) in
		(match op with
			|"not" -> (match accu_val with
					         | 0 -> accu := Entier 1
					         | 1 -> accu := Entier 0
					         | _ -> ())
			|"print" -> print_char (chr accu_val) ; accu := Entier 0
			| _ -> ());
			pc:=!pc+1

(* val prim : string -> unit *)
 let prim op =
		match op with
			|("+"|"-"|"/"|"*"|"or"|"and"|"<>"|"="|"<"|"<="|">"|">=") -> op_binaire op
			|("not"|"print") -> op_unaire op
			| _ -> ()

(* val branch : string -> unit *)
let branch lab =
	let pos_label = get_pos_label lab !prog in
		pc := pos_label

(* val branchifnot : string -> unit *)
let branchifnot lab =
	match !accu with
	|Entier(0) -> let pos_label = get_pos_label lab !prog in pc := pos_label
	|_ -> pc := !pc+1

(* val push : unit -> unit *)
let push () =
	stack := !accu::!stack;
	pc := !pc+1

(* val pop : unit -> unit *)
let pop () =
	stack := List.tl !stack;
	pc := !pc+1

(* val acc : int -> unit *)
let acc i =
	accu := List.nth !stack i;
	pc := !pc+1

(* val envacc : int -> unit *)
let envacc i =
	(match !env with
		|Env(e)-> accu := List.nth e i;
		| _ -> failwith "problème dans envacc");
	pc := !pc+1

(* val closure : string -> int -> unit *)
let closure lab n =
	if n > 0 then	stack := !accu::!stack;
	let pos_label = get_pos_label lab !prog in
		let val_depile = depile n in
			accu := Fermeture(pos_label,Env(val_depile));
			pc := !pc+1

(* val closure_rec : string -> int -> unit *)
let closure_rec lab n =
	if n > 0 then	stack := !accu::!stack;
	let pos_label = get_pos_label lab !prog in
		let val_depile = depile n in
			accu := Fermeture(pos_label,Env(Entier(pos_label)::val_depile));
			pc := !pc+1;
			stack := !accu::!stack

(* val apply : int -> unit *)
let apply n =
	let args_depile = depile n in
		let pile = args_depile@Entier(!extra_args)::Entier(!pc+1)::!env::[]@(!stack) in
		stack := pile;
		extra_args:=(n-1);
		match !accu with
		 	|Fermeture (p,e) -> (pc := p;
													 env := e)
			|_ -> failwith "Pas de fermeture dans accu"

(* val return : int -> unit *)
let return n =
	let _ = depile n in
	if !extra_args = 0 then
		begin
		extra_args := get_int (List.hd !stack);
		pc := get_int (List.hd (List.tl !stack));
		env := List.hd (List.tl (List.tl !stack));
		stack := List.tl (List.tl (List.tl !stack))
		end
	else
		begin
		extra_args := !extra_args - 1;
		match !accu with
			|Fermeture (p,e) -> pc := p; env:= e;
			|_ -> failwith "return : Pas de fermeture dans accu"

		end

(* val stop : unit -> 'a *)
let stop () = exit 0

(* val offset_closure : unit -> unit *)
let offset_closure () =
	(match !env with
		|Env(e) -> accu:=Fermeture(get_int (List.hd e),Env(e));
		| _ -> failwith "problème dans offset_closure");
	pc := !pc + 1

(* val grab : int -> unit *)
let grab n =
	if !extra_args >= n then (extra_args:=!extra_args-n; pc:=!pc+1)
	else
		begin
		let dep_args = depile (!extra_args+1) in
			accu:=Fermeture(!pc-1,Env(!env::dep_args));
		let dep_reste = depile 3 in
			extra_args := get_int (List.hd dep_reste);
			pc := get_int (List.nth dep_reste 1);
			env := List.nth dep_reste 2;
		end

(* val restart : unit -> unit *)
let restart () =
	(match !env with
		|Env(e) -> (let n = List.length e in
								extra_args := !extra_args + (n-1);
								stack := (List.tl e)@(!stack);
								env := Env((List.hd e)::[]));
		|_ -> failwith "problème dans restart");
		pc := !pc+1

(* val appterm : int -> int -> unit *)
let appterm n m =
	let args_depile = depile n in
	let _ =	depile (m-n) in
		stack:=args_depile@(!stack);
		(match !accu with
		 	|Fermeture (p,e) -> (pc := p;
													 env := e)
			|_ -> failwith "Pas de fermeture dans accu");
		extra_args:=!extra_args + (n-1)

(* val pushtrap : string -> unit *)
let pushtrap lab =
	stack:=Entier(get_pos_label lab !prog)::Entier(!trap_sp)::!env::[]@Entier(!extra_args)::!stack;
	trap_sp:= List.length !stack;
	pc:=!pc+1

(* val poptrap : unit -> unit *)
let poptrap () =
	pc:=!pc+1;
	let args_depile = depile 4 in
		match List.nth args_depile 1 with
		| Entier(res) -> trap_sp:=res;
		| _ -> failwith "pas normal"

(* val raisee : unit -> unit *)
let raisee () =
	if !trap_sp=(-1)
	then
		begin
			print_string "\n--------EXCEPTION--------\n";
			Printf.printf "code d'erreur : %d\n" (get_int(!accu));
			print_string "-------------------------\n";
			ignore(stop ())(*équivalent de stop ()*)
		end
	else
		let _ = depile ((List.length !stack) - !trap_sp)
		and args_depile = depile 4 in
			pc := get_int (List.hd args_depile);
			trap_sp := get_int (List.nth args_depile 1);
			env := Env((List.nth args_depile 2)::[]);
			extra_args := get_int (List.nth args_depile 3)

(* val makeblock : int -> unit *)
let makeblock n =
	let fst_content = Array.make 1 !accu in
		let depile_array = Array.of_list (depile (n-1)) in
			accu:=Bloc(Array.append fst_content depile_array);
	pc:=!pc+1

(* val getfield : int -> unit *)
let getfield n =
	(match !accu with
		|Bloc a -> accu:=Array.get a n
		|_ -> failwith "KO pas de bloc dans accu");
	pc:=!pc+1

(* val vectlength : unit -> unit *)
let vectlength () =
	(match !accu with
		|Bloc a -> accu:=Entier(Array.length a)
		|_ -> failwith "KO pas de bloc dans accu");
	pc:=!pc+1

(* val getvectitem : unit -> unit *)
let getvectitem () =
	(match depile 1 with
		|[Entier n] -> (match !accu with
											|Bloc a -> accu:=(Array.get a n)
											|_ -> failwith "KO pas de bloc dans accu")
	| _ -> failwith "KO pas d'entier dépilé");
	pc:=!pc+1

(* val setfield : int -> unit *)
let setfield n =
	let v = List.hd (depile 1) in
	(match !accu with
		|Bloc a -> Array.set a n v
		|_ -> failwith "KO pas de bloc dans accu");
	pc:=!pc+1

(* val setvectitem : unit -> unit *)
let setvectitem () =
	(match (depile 1) with
		|[Entier n] -> (match !accu with
											| Bloc a -> Array.set a n (List.hd (depile 1));accu:=Entier(0)
											| _ -> failwith "KO pas de bloc dans accu")
		|_ -> failwith "KO pas d'entier dépilé");
	pc:=!pc+1

(* val assign : int -> unit *)
let assign n =
	let rec assign_aux i l =
		match l with
		|h::t -> if i=0 then !accu::t else h::(assign_aux (i-1) t)
		|[]	-> failwith "Erreur index out of range"
	in
	stack:=(assign_aux n !stack);
	pc:=!pc+1
