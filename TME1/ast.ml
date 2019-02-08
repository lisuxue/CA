type expr = 
	ASTNum of int 
	
type instr = 
	ASTPrint of expr
	 
type prog = ASTProg of cmd list 

type cmd = ASTExpr of expr
	|ASTInstr of instr * cmd list
	|ASTExpr of expr * cmd list 
