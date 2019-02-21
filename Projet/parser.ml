
type triplet = {label:string; instr:string; args:string list} ;;

let list_triplet = []


let rec print_list_string = function 
[] -> ()
| e::l -> print_string e ; print_newline () ; print_list_string l;;


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
let make_record l =  
	begin 
		let label = ref false;
		let fst = List.hd l in  
			if String.contains fst ':' then label:=true;
		if !label then  (**)
			{label:List.nth l 0 ; instr:List.nth 1 ; args:make_arg_list List.nth 2}
		else
			{label:"" ; instr:List.nth 0 ; args:make_arg_list List.nth 1}
	end (*gerer le cas ou il n'y a pas d'argument !!!!!! *)



let make_arg_list str = 
	


let scan line = 
	begin
	let r = Str.regexp "[\t ]" in 
		 let liste = Str.split r line in 
		 	 make_record liste
	end
	
	

let parse fichier =
	let f = open_in fichier in
		let rec parse_rec () =
			try
				(let line = input_line f in 
					let record = scan line;
				 parse_rec ()
				)
			with End_of_file -> close_in f
		in parse_rec ();;

parse Sys.argv.(1);;

