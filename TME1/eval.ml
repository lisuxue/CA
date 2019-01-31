open Ast

let print_val e = 
 match e with
 	 | Int of int -> print_int(e)
	 | Bool of bool -> print_bool(e)
	 | Unit -> ();


let rec eval e = print_val(eval e1);



let _ = 
	let lexbuf = Lexing.from_channel stdin in 
	let ast = Parser.prog Lexer.token lexbuf in 
	let result  = eval ast in 
	print_int result;;
	

