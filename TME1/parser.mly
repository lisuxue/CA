%{ open Ast %}
%token PRINT, EOL
%token <int> INTEGER
%start prog
%type <Ast.prog> prog
%type <Ast.expr> expr


%%

prog : 
    PRINT expr {ASTPrint($2)}
;  

expr : 
    INTEGER {ASTNum($1)} 
;
