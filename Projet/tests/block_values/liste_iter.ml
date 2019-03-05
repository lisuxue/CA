let rec iter f l =
  match l with
   | [] -> ()
   | h::t -> f h ; iter f t

let _ =
  let l = [] in
  let l = 'R'::l in
  let l = 'U'::l in
  let l = 'O'::l in
  let l = 'J'::l in
  let l = 'N'::l in
  let l = 'O'::l in
  let l = 'B'::l in
  iter print_char l
