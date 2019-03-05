let _ =
  let a = [| 0 ; 0 ; 0 |] in
  for i = 0 to 2 do
    a.(i) <- i
  done;
  a
