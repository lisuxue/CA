let entier = ref 0

let plus n =
  entier:=(!entier)+n

let print_entier n = plus n;print_int !entier;print_newline ();
