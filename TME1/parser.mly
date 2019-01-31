%{ open Ast %}
%token PRINT, EOL
%token <int> INTEGER
%start prog
%type <Ast.value> prog
%type <Ast.value> print
%type <Ast.value> expr
%type <Ast.value> expr_print

%%

prog : print EOL {$1}  
print : PRINT expr_print {Print($2)}
expr_print : expr {$1}

		
expr : INTEGER {Int($1)} 

