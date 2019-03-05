exception Div_zero


let div x y =
  if y = 0 then raise Div_zero
  else x / y

let safe_div x y =
  try
    div x y
  with
  | Div_zero -> 0

let _ =
  safe_div 2 0
