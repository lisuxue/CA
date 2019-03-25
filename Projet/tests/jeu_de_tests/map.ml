let rec mymap f l =
  match l with
  | [] -> []
  | hd::tl -> (f hd)::mymap f tl;;


mymap (fun x -> x + 1) [1;2;3;4];;
