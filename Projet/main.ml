open Parser

type mlvalue = Entier of int | Fermeture of int * mlvalue list

(*registres de la Mini-ZAM*)
let prog = (parse Sys.argv.(1))(*liste des triplet d'instructions*)
let stack = ref [] (*pile Last In First Out*)
let env = ref [] (*environnement courant*)
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

let op_binaire op =
	let val_stack = List.hd !stack in
		match op with
		|"+" -> accu := !accu + val_stack
		|"-" -> accu := !accu - val_stack
		|"/" -> accu := !accu / val_stack
		|"*" -> accu := !accu * val_stack
		|"or" -> accu := !accu || val_stack
		|"and" -> accu := !accu && val_stack
		|"<>" -> accu := !accu <> val_stack
		|"=" -> accu := !accu = val_stack  (* a verifier si = de ZAM est = ou == en ocaml (egalite structurelle ou physique) *)
		|"<" -> accu := !accu < val_stack
		|"<=" -> accu := !accu <= val_stack
		|">" -> accu := !accu > val_stack
		|">=" -> accu := !accu >= val_stack;
	stack := List.tl !stack

let op_unaire op =
	match op with
		|"not" -> accu := not !accu
		|"print" -> print_int !accu ; accu := 0

let prim op =
	match op with
		|("+"|"-"|"/"|"*"|"or"|"and"|"<>"|"="|"<"|"<="|">"|">=") -> op_binaire op
		|("not"|"print") -> op_unaire op

(* let branch lab =
	let pos_label =
		let rec find x l =
    		match l with
   			| [] -> raise (Failure "Not Found")
    		| {label=y;_} as h::t -> if x = y then 0 else 1 + find x t
    	in find lab prog *)
