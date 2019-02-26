open Parser

type mlvalue = E of int | F of int * mlvalue list 

(*registres de la Mini-ZAM*)
let prog = (parse Sys.argv.(1));;(*liste des triplet d'instructions*)
let stack = []; (*pile Last In First Out*) 
let env = []; (*envirronement courant*)
let pc = ref 0; (*pointeur sur la ligne courante*)
let accu = ref 0; (*registre temporaire de type mlvalue*) 


