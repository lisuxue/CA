open Main
open Parser

type mlvalue = E of int | F of ( int * mlvalue list )

print_prog prog;;

