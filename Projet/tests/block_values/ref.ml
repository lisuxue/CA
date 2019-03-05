let incr r = r := !r + 1

let _ =
  let r = ref 2 in
  incr r;
  !r
