exception E

let _ =
  try
    try
      raise E
    with
      E -> raise E
  with E -> 23
