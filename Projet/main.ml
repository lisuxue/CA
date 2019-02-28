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
il faut accéder à la i eme valeur de la pile, et avec Stack on peut pas le faire de manière simple.
Même si le pop de Stack est très facile d'utilisation, on peut cependant simuler un pop avec une liste,
en tout cas l'inconvénient de la liste est plus facile à contourner.
*)

(* voir au niveau de prof si c'est mieux ou pas de faire un triplet ou doublet au lieu de ça *)
(* voir si vaut mieux implementer stack de la facon du fichier teststack ou pas *)


let const n =
	accu := n

let get_int i =
	match i with
	| Entier i -> i
  | _ -> 0

let int_of_bool b = if b then 1 else 0

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
	stack := List.tl !stack

let op_unaire op =
	let accu_val = (get_int !accu) in
		match op with
			|"not" ->
				(match accu_val with
					| 0 -> accu := Entier 1
					| 1 -> accu := Entier 0
					| _ -> ())
			|"print" -> print_int accu_val ; accu := Entier 0
			| _ -> ()

let prim op =
	match op with
		|("+"|"-"|"/"|"*"|"or"|"and"|"<>"|"="|"<"|"<="|">"|">=") -> op_binaire op
		|("not"|"print") -> op_unaire op
		| _ -> ()

(*
let branch lab =
	let pos_label =
		let rec find x l =
    		match l with
   			| [] -> raise (Failure "Not Found")
    		| {label=y;_} as h::t -> if x = y then 0 else 1 + find x t
    	in find lab prog*)
