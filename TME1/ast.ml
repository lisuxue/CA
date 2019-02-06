type expr = 
	ASTNum of int 
	|ASTPrint of expr
type prog = expr

