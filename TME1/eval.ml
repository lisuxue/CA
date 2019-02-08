open Ast

let evalPrint e = e;;

let rec eval e = 
	match e with 
	Ast.ASTNum e1 -> e1
	|Ast.ASTPrint e1 -> eval e1;;

let _ = 
	let lexbuf = Lexing.from_channel stdin in 
	let ast = Parser.prog Lexer.token lexbuf in 
	let result  = eval ast in 
	print_int result;;
