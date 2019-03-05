let add_couples c =
  let (a,b) = c in
  a+b

let _ =
  let a = 64 in
  let b = 36 in
  let c = (a,b) in
  add_couples c
