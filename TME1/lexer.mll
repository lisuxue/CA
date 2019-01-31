{open Parser}
let integer = '-'?['0'-'9']+
let spaces = [' ' '\t']
let pv = ';'
let eol = '\n'

rule token = parse 
	spaces {token lexbuf}
	|integer as x {INTEGER(int_of_string x)}
	|"PRINT" {PRINT}
	|eol {EOL}


