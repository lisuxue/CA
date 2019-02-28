type triplet = {
	label:string option;
	instr:string;
	args:string list
}

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
let print_triplet {label;instr;args} =
	match label with
		|Some l -> Printf.printf "{label:\"%s\" , instr:\"%s\" , args : %s}" l instr (print_list_string args);print_newline ()
		|_ -> failwith "Ne devrait pas arriver"


(* val make_record : string list -> triplet retourne le triplet correspondant à la ligne donnée*)
let make_record l =
		let fst = List.hd l in
			if String.contains fst ':' then
				let length = (String.length fst) - 1 in
					let label_name = Some(String.sub (List.hd l) 0 length) in
						{label=label_name; instr=List.hd (List.tl l) ; args=List.tl (List.tl l)}
			else
  	    		{label=None; instr=List.hd l; args=List.tl l}

(* val scan : in_channel -> triplet : enlève les séparateurs de la ligne  *)
let scan line =
	let delim = Str.regexp "[, \t]+" in
		 let liste = Str.split delim line in
		 	  make_record liste


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
				  		print_prog t
