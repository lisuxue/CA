

let rec list_length l =
  match l with
    | [] -> 0
    | h::t -> 1 + list_length t

let _ =
  let l = [] in
  let l = 3::l in
  let l = 2::l in
  let l = 1::l in
  list_length l
