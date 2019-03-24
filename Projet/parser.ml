(***********************
			INSTRUCTIONS
************************)
type triplet = {
	label:string option;
	instr:string;
	args:string list
}

(***********************
				AFFICHAGES
************************)
(* val print_triplet : string list -> string*)
let rec print_list_string =
	function
	[] -> "[]"
	| e::l -> e^"::"^print_list_string l

(* val print_triplet : triplet -> unit*)
let print_triplet {label;instr;args} =
	match label with
		|Some l -> Printf.printf "{label:\"%s\" , instr:\"%s\" , args : %s}" l instr (print_list_string args);print_string "\t"
		|None -> Printf.printf "{label:\" \" , instr:\"%s\" , args : %s}" instr (print_list_string args);print_string "\t"

(* val print_prog : triplet list -> unit*)
let rec print_prog list_triplet =
	match list_triplet with
		|[] -> ()
		| h::t ->	print_triplet h;
							print_string "\n";
				  		print_prog t

(***********************
				PARSING
************************)
(* val make_record : string list -> triplet*)
let make_record l =
		let fst = List.hd l in
			if String.contains fst ':' then
				let length = (String.length fst) - 1 in
					let label_name = Some(String.sub (List.hd l) 0 length) in
						{label=label_name; instr=List.hd (List.tl l) ; args=List.tl (List.tl l)}
			else
  	    		{label=None; instr=List.hd l; args=List.tl l}

(* val scan : string -> triplet*)
let scan line =
	let delim = Str.regexp "[, \t]+" in
		 let liste = Str.split delim line in
		 	  make_record liste

(* val parse : string -> triplet list*)
let parse fichier =
	let f = open_in fichier in
		let rec parse_rec () =
			try
				let line = input_line f in
				  (scan line)::(parse_rec ())
			with End_of_file -> close_in f;[]
		in parse_rec ()
