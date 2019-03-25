exception ListVide

let tete l =
  match l with
  [] -> raise ListVide
  | hd::tl -> hd;;

let l = [1] in
  try
    tete l
  with ListVide -> 0
