type token =
  | PRINT
  | EOL
  | INTEGER of (int)

val prog :
  (Lexing.lexbuf  -> token) -> Lexing.lexbuf -> Ast.value
