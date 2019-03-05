let _ =
  let a = [| 1 ; 2 ; 3 |] in
  let r = ref 0 in
  for i = 0 to Array.length a - 1 do
    r := !r + a.(i);
  done;
  !r
