open Parser

type mlvalue = Entier of int | Fermeture of int * mlvalue list

(*registres de la Mini-ZAM*)
let prog = (parse Sys.argv.(1))(*liste des triplet d'instructions*)
let stack : mlvalue list ref = ref []  (*pile Last In First Out*)
let env : mlvalue list ref = ref [] (*environnement courant*)
let pc = ref 0 (*pointeur sur la ligne courante*)
let accu = ref (Entier 0) (*registre temporaire de type mlvalue*)

(*
on choisit d'implémenter la pile avec List et pas Stack car dans l'instruction ACC i,
il faut accéder à la i eme valeur de la pile, et avec Stack on peut pas
le faire de manière simple.
Même si le pop de Stack est très facile d'utilisation, on peut cependant
simuler un pop avec une liste, en tout cas l'inconvénient de la liste
est plus facile à contourner.
*)

(* record prend moins de place qu'un tuple de tuple, de plus plus facile d'utilisation*)


let const n =
	accu := n

let get_int value =
	match value with
	| Entier i -> i
  | _ -> 0

let int_of_bool b =
	if b then 1 else 0

let op_binaire op =
	let stack_val = (get_int (List.hd !stack)) in
		let accu_val = (get_int !accu) in
		match op with
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
			| _ -> ();
	stack := List.tl !stack;
	pc := !pc+1

let op_unaire op =
	let accu_val = (get_int !accu) in
		match op with
			|"not" -> (match accu_val with
					         | 0 -> accu := Entier 1
					         | 1 -> accu := Entier 0
					         | _ -> ())
			|"print" -> print_int accu_val ; accu := Entier 0
			| _ -> ();
	pc := !pc+1

let prim op =
	match op with
		|("+"|"-"|"/"|"*"|"or"|"and"|"<>"|"="|"<"|"<="|">"|">=") -> op_binaire op
		|("not"|"print") -> op_unaire op
		| _ -> ();
	pc := !pc+1

let rec get_pos_label label list_record =
	match list_record with
		| {label=Some x;_}::tl when x=label -> 0
		| [] -> failwith "Le label demandé n'existe pas"
		| hd::tl -> 1 + get_pos_label label tl

let branch lab =
	let pos_label = get_pos_label lab !stack in
		pc := pos_label

let branchifnot lab =
	let accu_val = (get_int !accu) in
		if accu_val=0
		then let pos_label = get_pos_label lab !stack in
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
	pc := pc+1

let envacc i =
	accu := List.nth !env i;
	pc := pc+1

let depile n =
	match n with
		|0 -> []
		|_ -> let e = (List.hd !stack) in
						(stack:=(List.tl !stack);
						e::(depile (n-1)))

let closure lab n =
	if n > 0 then	stack := !accu::!stack;
	let pos_label = get_pos_label lab !stack in
		let val_depile = depile n in
			accu := Fermeture(pos_label,val_depile);
			pc := pc+1

let apply n =
	let args_depile = depile n in
		stack := args_depile@Entier(!p+1)::!env::!stack; (*a verifier*)
		match !accu with
		 	|Fermeture(p,e) -> pc := p; env := e
			|_ -> failwith "Pas de fermeture dans accu";
		pc := pc+1


let return n =
	let _ = depile n;
	pc := List.hd !stack;
	stack := List.tl !stack;
	env := List.hd !stack;
	stack := List.tl !stack

let stop () = exit O (*a verifier*)
