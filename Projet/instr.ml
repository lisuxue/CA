open Main
open Parser

type mlvalue = Entier of int | Fermeture of ( int * mlvalue list )

print_prog prog;;

