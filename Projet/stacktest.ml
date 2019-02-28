(*let stack = ref List.empty

module Mystack = 
struct
  include List
  let pop l = match l with 
  	|[] -> failwith "Cannot pop an empty stack!"
	| t::q -> (stack := q ; t) ;;

end*)

type pile = {mutable liste : mlvalue list} ;;
exception Empty ;;
let newpile () = {liste = []} ;;
let push x p = p.liste = x::p.liste ;;
let pop p = match p.liste with
 [] -> raise Empty
| t::q -> (p.liste = q ; t) ;;

let s = newpile () in 
	try pop s
	with Empty -> print_string "Attention erreur" ;;

