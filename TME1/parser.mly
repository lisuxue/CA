%{ open Ast %}
%token PRINT, EOL
%token <int> INTEGER
%start prog
%type <Ast.print> prog
%type <Ast.print> print
%type <Ast.expr> expr

%%

prog : 
    print {$1}
;  

print : 
    PRINT expr {ASTPrint($2)}
;

expr : 
INTEGER {ASTNum($1)} 
;
