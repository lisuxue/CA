exception E
exception F

let _ =
  try
    try
      raise F
    with | E -> 42
  with | F -> 88
