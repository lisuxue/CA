open Parser
open Minizam

(*PROGRAMME PRINCIPAL*)
let main =
		print_string "----------------------------------";print_newline();
		print_string "Out :";
		prog := passe (!prog);
		let rec run prog=
			let courant = List.nth prog ((!pc)) in
				match courant with
				|{label;instr="CONST";args} -> const (Entier(int_of_string(List.hd args)));run prog
				|{label;instr="PRIM";args} -> prim (List.hd args);run prog
				|{label;instr="BRANCH";args} -> branch (List.hd args);run prog
				|{label;instr="BRANCHIFNOT";args} -> branchifnot (List.hd args);run prog
				|{label;instr="PUSH";_} -> push ();run prog
				|{label;instr="POP";_} -> pop ();run prog
				|{label;instr="ACC";args} -> acc (int_of_string(List.hd args));run prog
				|{label;instr="ENVACC";args} -> envacc (int_of_string(List.hd args));run prog
				|{label;instr="CLOSURE";args} -> closure (List.hd args) (int_of_string (List.nth args 1));run prog
				|{label;instr="CLOSUREREC";args} -> closure_rec (List.hd args) (int_of_string (List.nth args 1));run prog
				|{label;instr="OFFSETCLOSURE";args} -> offset_closure ();run prog
				|{label;instr="APPLY";args} -> apply (int_of_string (List.hd args));run prog
				|{label;instr="RETURN";args} -> return (int_of_string (List.hd args));run prog
				|{label;instr="GRAB";args} -> grab (int_of_string (List.hd args));run prog
				|{label;instr="RESTART";args} -> restart ();run prog
				|{label;instr="APPTERM";args} -> appterm (int_of_string (List.hd args)) (int_of_string (List.nth args 1));run prog
				|{label;instr="PUSHTRAP";args} -> pushtrap (List.hd args);run prog
				|{label;instr="POPTRAP";args} -> poptrap ();run prog
				|{label;instr="RAISE";args} -> raisee ();run prog
				|{label;instr="MAKEBLOCK";args} -> makeblock (int_of_string (List.hd args));run prog
				|{label;instr="GETFIELD";args} -> getfield (int_of_string (List.hd args));run prog
				|{label;instr="VECTLENGTH";_} -> vectlength ();run prog
				|{label;instr="GETVECTITEM";_} -> getvectitem ();run prog
				|{label;instr="SETFIELD";args} -> setfield (int_of_string (List.hd args));run prog
				|{label;instr="SETVECTITEM";_} -> setvectitem ();run prog
				|{label;instr="ASSIGN";args} -> assign (int_of_string (List.hd args));run prog
				|{label;instr="STOP";_} -> print_string "\nRes :";print_mlvalue (!accu);print_newline();
																	 print_string "----------------------------------";print_newline();
																	 stop ()
				| _ -> failwith "commande inconnue"
		in run (!prog);;
