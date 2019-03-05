let rec insert x l =
  match l with
  | [] -> [x]
  | y::ys ->
    if x < y then x::y::ys
    else
      y::(insert x ys)

let rec insert_sort l =
    match l with
    | [] -> []
    | x::xs -> insert x (insert_sort xs)

let _ = insert_sort [3;2;5;4;1]
