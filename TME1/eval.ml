open Ast

let evalPrint e = print_int(e);

let rec eval e = evalPrint(eval e1);



let _ = 
	let lexbuf = Lexing.from_channel stdin in 
	let ast = Parser.prog Lexer.token lexbuf in 
	let result  = eval ast in 
	result;;