{open Parser}
rule token = parse 
	(* separateurs *)
	[' ' '\t'] {token lexbuf}
	| ['\n'] { EOL }
	(* constantes numériques *)
	| ('-')?['0'-'9']+ as x {INTEGER(int_of_string x)}
	(* primitives *)
	| "PRINT" { PRINT }


