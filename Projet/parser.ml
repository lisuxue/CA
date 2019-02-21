type triplet = {label:string; instr:string; args:string list} ;;

let scan line = 
	
	print_string line;print_newline ();;
	
let parse fichier =
	let f = open_in fichier in
		let rec parse_rec () =
			try
				(let line = input_line f in scan line;
				 parse_rec ()
				)
			with End_of_file -> close_in f
		in parse_rec ();;

parse Sys.argv.(1);;
