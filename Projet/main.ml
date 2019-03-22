open Parser;;
open Char;;

type mlvalue = Entier of int
						 | Fermeture of int * mlvalue
						 | Env of mlvalue list
(*registres de la Mini-ZAM*)
let prog : triplet list ref = ref (parse Sys.argv.(1))(*liste des triplet d'instructions type = triplet list*)
let stack : mlvalue list ref = ref []  (*pile Last In First Out*)
let env : mlvalue ref = ref (Env([])) (*environnement courant*)
let pc = ref 0 (*pointeur sur la ligne courante*)
let accu = ref (Entier 0) (*registre temporaire de type mlvalue*)
let extra_args = ref 0
let trap_sp = ref (-1)

(* UTILITAIRES *)
(*
on choisit d'implémenter la pile avec List et pas Stack car dans l'instruction ACC i,
il faut accéder à la i eme valeur de la pile, et avec Stack on peut pas
le faire de manière simple.
Même si le pop de Stack est très facile d'utilisation, on peut cependant
simuler un pop avec une liste, en tout cas l'inconvénient de la liste
est plus facile à contourner.
*)
(* record prend moins de place qu'un tuple de tuple, de plus plus facile d'utilisation*)
let get_int value =
	match value with
	| Entier i -> i
  | _ -> 0

let int_of_bool b =
	if b then 1 else 0

let rec depile n =
	match n with
		|0 -> []
		|_ -> let e = (List.hd !stack) in
			(stack:=(List.tl !stack);
			e::(depile (n-1)))

let rec get_pos_label label list_record =
	match list_record with
	| {label=Some x;_}::tl when x=label -> 0
	| [] -> failwith "Le label demandé n'existe pas"
	| hd::tl -> 1 + get_pos_label label tl

let rec print_list_aux l =
	(match l with
	| [] -> ()
	| hd::tl -> print_mlvalue hd;
							if tl==[] then print_list_aux tl
												else print_string ";";print_list_aux tl)

and print_mlvalue m =
	match m with
	| Entier v -> print_int v
	| Fermeture(v,l)-> print_string "{";print_int v;print_string ",";print_string"[";print_mlvalue l;print_string"]";print_string"}"
	| Env(l) -> print_string"[";print_list_aux l;print_string"]"

let passe prog =
	let res : triplet list ref = ref [] in
		let rec aux prog=
			(match prog with
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
				|[] -> !res)
		in aux prog;;

(* OPERATIONS *)
let const n =
	accu := n;
	pc := !pc+1

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

let op_unaire op =
	let accu_val = (get_int !accu) in
		(match op with
			|"not" -> (match accu_val with
					         | 0 -> accu := Entier 1
					         | 1 -> accu := Entier 0
					         | _ -> ())
			|"print" -> print_string "print : "; print_char (chr accu_val) ; accu := Entier 0
			| _ -> ());
			pc:=!pc+1

 let prim op =
		match op with
			|("+"|"-"|"/"|"*"|"or"|"and"|"<>"|"="|"<"|"<="|">"|">=") -> op_binaire op
			|("not"|"print") -> op_unaire op
			| _ -> ()

let branch lab =
	let pos_label = get_pos_label lab !prog in
		pc := pos_label

let branchifnot lab =
	let accu_val = (get_int !accu) in
		if accu_val=0
			then let pos_label = get_pos_label lab !prog in
					pc := pos_label
			else pc := !pc+1

let push () =
	stack := !accu::!stack;
	pc := !pc+1

let pop () =
	stack := List.tl !stack;
	pc := !pc+1

let acc i =
	accu := List.nth !stack i;
	pc := !pc+1

let envacc i =
	(match !env with
		|Env(e)-> accu := List.nth e i;
		| _ -> failwith "problème dans envacc");
	pc := !pc+1

let closure lab n =
	if n > 0 then	stack := !accu::!stack;
	let pos_label = get_pos_label lab !prog in
		let val_depile = depile n in
			accu := Fermeture(pos_label,Env(val_depile));
			pc := !pc+1

let closure_rec lab n =
	if n > 0 then	stack := !accu::!stack;
	let pos_label = get_pos_label lab !prog in
		let val_depile = depile n in
			accu := Fermeture(pos_label,Env(Entier(pos_label)::val_depile));
			pc := !pc+1;
			stack := !accu::!stack

let apply n =
	let args_depile = depile n in
		let pile = args_depile@Entier(!extra_args)::Entier(!pc+1)::!env::[]@(!stack) in
		stack := pile;
		extra_args:=(n-1);
		match !accu with
		 	|Fermeture (p,e) -> (pc := p;
													 env := e)
			|_ -> failwith "Pas de fermeture dans accu"

let return n =
	let _ = depile n in
	if !extra_args = 0 then
		begin
		extra_args := get_int (List.hd !stack);
		pc := get_int (List.hd (List.tl !stack));
		env := Env(List.hd (List.tl (List.tl !stack))::[]);
		stack := List.tl (List.tl (List.tl !stack))
		end
	else
		begin
		extra_args := !extra_args - 1;
		match !accu with
			|Fermeture (p,e) -> pc := p; env:= e;
			|_ -> failwith "return : Pas de fermeture dans accu"

		end

let stop () = exit 0

let offset_closure () =
	(match !env with
		|Env(e) -> accu:=Fermeture(get_int (List.hd e),Env(e));
		| _ -> failwith "problème dans offset_closure");
	pc := !pc + 1

let grab n =
	if !extra_args >= n then (extra_args:=!extra_args-n; pc:=!pc+1)
	else
		begin
		let dep_args = depile (!extra_args+1) in
			(match !env with
				|Env(e) -> accu := Fermeture(!pc-1,Env(e@dep_args));
				|_ -> failwith "problème dans grab");
			let dep_rest = depile 3 in
			extra_args := get_int (List.hd dep_rest);
			pc := get_int (List.hd (List.tl dep_rest));
			env := Env(List.tl (List.tl dep_rest));
		end

let restart () =
	(match !env with
		|Env(e) -> (let n = List.length e in
								extra_args := !extra_args + (n-1);
								stack := (List.tl e)@(!stack);
								env := Env((List.hd e)::[]));
		|_ -> failwith "problème dans restart");
		pc := !pc+1

let appterm n m =
	let args_depile = depile n in
	let _ =	depile (m-n) in
		stack:=args_depile@(!stack);
		(match !accu with
		 	|Fermeture (p,e) -> (pc := p;
													 env := e)
			|_ -> failwith "Pas de fermeture dans accu");
		extra_args:=!extra_args + (n-1)

let pushtrap lab =
	stack:=Entier(get_pos_label lab !prog)::Entier(!trap_sp)::!env::[]@Entier(!extra_args)::!stack;
	trap_sp:= List.length !stack;
	pc:=!pc+1

let poptrap () =
	pc:=!pc+1;
	let args_depile = depile 4 in
		match List.nth args_depile 1 with
		| Entier(res) -> trap_sp:=res;
		| _ -> failwith "pas normal"


let raisee () =
	if !trap_sp=(-1)
	then begin
		print_string "\n--------EXCEPTION--------\n";
		Printf.printf "code d'erreur : %d\n" (get_int(!accu));
		print_string "-------------------------\n";
		exit 0; (*équivalent de stop ()*)
		end
	else
		depile ((List.length !stack) - !trap_sp);
		let args_depile = depile 4 in
			pc := get_int (List.hd args_depile);
			trap_sp := get_int (List.nth args_depile 1);
			env := Env((List.nth args_depile 2)::[]);
			extra_args := get_int (List.nth args_depile 3)



let main = (* parcourt de la liste avec pc sans réelle recursion  *)
		prog := (passe !prog);
		print_string "passe : \n";print_prog (passe !prog);print_newline();
		print_string "au début : pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=[";print_mlvalue !env;print_string "]";print_string " trap_sp="; print_int !trap_sp;print_newline ();
		let rec run prog=
			let courant = List.nth prog !pc in
				match courant with
				|{label;instr="CONST";args} -> print_triplet courant;
																			 const (Entier(int_of_string(List.hd args)));
																			 print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=[";print_mlvalue !env;print_string "]";print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																			 run prog
				|{label;instr="PRIM";args} -> print_triplet courant;
																			prim (List.hd args);
																			print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=[";print_mlvalue !env;print_string "]";print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																			run prog
				|{label;instr="BRANCH";args} -> print_triplet courant;
																				branch (List.hd args);
																				print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=[";print_mlvalue !env;print_string "]";print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																				run prog
				|{label;instr="BRANCHIFNOT";args} -> print_triplet courant;
																						 branchifnot (List.hd args);
																						 print_string "-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=[";print_mlvalue !env;print_string "]";print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																						 run prog
				|{label;instr="PUSH";_} -> print_triplet courant;
																	 push ();
																	 print_string "\t\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=[";print_mlvalue !env;print_string "]";print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																	 run prog
				|{label;instr="POP";_} -> print_triplet courant;
																	pop ();
																	print_string "\t\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=[";print_mlvalue !env;print_string "]";print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																	run prog
				|{label;instr="ACC";args} -> print_triplet courant;
																		 acc (int_of_string(List.hd args));
																		 print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=[";print_mlvalue !env;print_string "]";print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																		 run prog
				|{label;instr="ENVACC";args} -> print_triplet courant;
																				envacc (int_of_string(List.hd args));
																				print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=[";print_mlvalue !env;print_string "]";print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																				run prog
				|{label;instr="CLOSURE";args} -> print_triplet courant;
																				 closure (List.hd args) (int_of_string (List.nth args 1));
																				 print_string "-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=[";print_mlvalue !env;print_string "]";print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																				 run prog
				|{label;instr="CLOSUREREC";args} -> print_triplet courant;
				 																 closure_rec (List.hd args) (int_of_string (List.nth args 1));
																				 print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=[";print_mlvalue !env;print_string "]";print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																				 run prog
				|{label;instr="OFFSETCLOSURE";args} -> print_triplet courant;
																				 offset_closure ();
																			 	 print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=[";print_mlvalue !env;print_string "]";print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																	 			 run prog
				|{label;instr="APPLY";args} -> print_triplet courant;
																			 apply (int_of_string (List.hd args));
																			 print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=[";print_mlvalue !env;print_string "]";print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																			 run prog
				|{label;instr="RETURN";args} -> print_triplet courant;
																				return (int_of_string (List.hd args));
																				print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=[";print_mlvalue !env;print_string "]";print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																				run prog
				|{label;instr="GRAB";args} -> print_triplet courant;
																			grab (int_of_string (List.hd args));
																			print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=[";print_mlvalue !env;print_string "]";print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																			run prog
				|{label;instr="RESTART";args} -> print_triplet courant;
																				 restart ();
																				 print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=[";print_mlvalue !env;print_string "]";print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																				 run prog
				|{label;instr="APPTERM";args} -> print_triplet courant;
																				 appterm (int_of_string (List.hd args)) (int_of_string (List.nth args 1));
				  														   print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=[";print_mlvalue !env;print_string "]";print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
	 																		   run prog

				|{label;instr="PUSHTRAP";args} -> print_triplet courant;
																			 	 	pushtrap (List.hd args);
																 				 	print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=[";print_mlvalue !env;print_string "]";print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																 	 			 	run prog
				|{label;instr="POPTRAP";args} -> print_triplet courant;
																 				 poptrap ();
																 				 print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=[";print_mlvalue !env;print_string "]";print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																 				 run prog
				|{label;instr="RAISE";args} -> print_triplet courant;
																 			 raisee ();
																 			 print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=[";print_mlvalue !env;print_string "]";print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																 			 run prog
				|{label;instr="STOP";_} -> print_triplet courant;
																	 print_newline();
																	 print_string "-------------RESULTAT-------------";print_newline();
																	 print_string "\t\t";print_mlvalue !accu;print_newline();
																	 print_string "----------------------------------";print_newline();
																	 stop ()
				| _ -> failwith "commande inconnue"
		in run !prog;;
