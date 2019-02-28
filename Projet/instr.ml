open Parser

type mlvalue = Entier of int | Fermeture of ( int * mlvalue list )
let prog = parse Sys.argv.(0) in
  print_prog prog
