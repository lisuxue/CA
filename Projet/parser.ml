
type triplet = {
	label:string;
	instr:string;
	args:string list
};;

let list_triplet = [];;

(* val print_triplet : string list -> unit*)
let rec print_list_string =
	function
	[] -> ()
	| e::l -> print_string e;print_string "::"; print_list_string l;;

(* val print_triplet : triplet -> unit*)
let print_triplet {label;instr;args} =
	Printf.printf "label : \"%s\",instr : \"%s\",args : [" label instr;print_list_string args;print_string "[]]";print_newline ()

(*
on ne peut pas passer de la liste de string en enregistrement par une fonction recursive
du coup make_record est itérative parcourt les elements de la liste passée en paramètre et
verifie si le premier element contient le caractère ':' si oui met une variable de controle de presence de label a true, si non ne fait rien, ensuite
selon que la var de controle soit true ou false :
true :
	prend le premier element comme label, le deuxieme comme instruction et le dernier string de la liste (si il existe) est passé en argument de l'appel à la fonction make_arg_list
false :
	prend le premier element comme instruction , et le reste idem
*)




(* val make_record : string list -> unit (record) affiche le triplet correspondant à la ligne donnée*)
let make_record l =
		let fst = List.hd l in
			if String.contains fst ':' then
				print_triplet {label= List.hd l; instr=List.hd (List.tl l) ; args=List.tl (List.tl l)}
			else
  	    print_triplet {label= ""; instr=List.hd l; args=List.tl l}
		(*let label = ref false;
		let fst = List.hd l in
			if String.contains fst ':' then label:=true;
		if !label then
			print_triplet {label= (List.nth l 0); instr=(List.nth 1) ; args=make_arg_list List.nth 2}
		else
			print_triplet {label= "" ; instr=(List.nth 0) ; args=make_arg_list (List.nth 1)}
			(*gerer le cas ou il n'y a pas d'argument !!!!!!*)

  let make_arg_list str = *)

(* val scan : in_channel -> unit (type à changer plus tard par (record))  *)
let scan line =
	let delim = Str.regexp "[, \t]+" in
		 let liste = Str.split delim line in
		 	  make_record liste


(* val parse : in_channel -> unit (pareil) *)
let parse fichier =
	let f = open_in fichier in
		let rec parse_rec () =
			try
				(let line = input_line f in
				  scan line;
				  parse_rec ()
				)
			with End_of_file -> close_in f
		in parse_rec ();;

parse Sys.argv.(1);;
