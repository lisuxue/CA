
type triplet = (string * (string * string list))

(*
permet de matcher directement sur les noms des champs par exemple :
 let t = { label="L1";instr="CONST";args=[]};;

 match t with 
| {label="L2";_} -> print_string "Bonjour"
| {label="L3";_} -> print_string "C'est ca"
| {instr="CONST";_} -> print_string "c'est celui la mtn";; 

resultat : c'est celui la mtn- : unit = ()
*)

let list_triplet = []

(* val print_triplet : string list -> unit*)
let rec print_list_string =
	function
	[] -> "[]"
	| e::l -> e^"::"^print_list_string l

(* val print_triplet : triplet -> unit*)
let print_triplet (label,(instr,args)) =
	Printf.printf "(label:\"%s\" , (instr:\"%s\" , args : %s))" label instr (print_list_string args);print_newline ()


(* val make_tuple : string list -> triplet affiche le triplet correspondant à la ligne donnée*)
let make_tuple l =
		let fst = List.hd l in
		let label_length = (String.length fst) - 1 in
			if String.contains fst ':' then
				(String.sub (List.hd l) 0 label_length,(List.hd (List.tl l),List.tl (List.tl l)))
			else
  	    		("",(List.hd l,List.tl l))

(* val scan : in_channel -> triplet : enlève les séparateurs de la ligne  *)
let scan line =
	let delim = Str.regexp "[, \t]+" in
		 let liste = Str.split delim line in
		 	  make_tuple liste

(* val parse : in_channel -> triplet list *)
let parse fichier =
	let f = open_in fichier in
		let rec parse_rec () =
			try
				let line = input_line f in
				  List.cons (scan line) (parse_rec ())
				 
			with End_of_file -> close_in f;[]
		in parse_rec ()

(* val print_prog : in_channel -> triplet list *)
let rec print_prog list_triplet = 
	match list_triplet with 
		| [] -> ()
		| h::t -> print_triplet h;
				  print_prog t;; 
				  
print_prog (parse Sys.argv.(1));;

