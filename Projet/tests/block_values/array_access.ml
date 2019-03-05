let _ =
  let a = [| 0 |] in
  let b = 0 in
  a.(b) <- 1;
  a.(b)
