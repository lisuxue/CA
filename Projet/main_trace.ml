open Parser
open Minizam

(*PROGRAMME PRINCIPAL*)
let main =
		prog := (passe !prog);
		print_string "passe du programme : \n";print_prog !prog;print_newline();
		print_string "au début : pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " trap_sp="; print_int !trap_sp;print_newline ();
		let rec run prog=
			let courant = List.nth prog !pc in
				match courant with
				|{label;instr="CONST";args} -> print_triplet courant;
																			 const (Entier(int_of_string(List.hd args)));
																			 print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																			 run prog
				|{label;instr="PRIM";args} -> print_triplet courant;
																			prim (List.hd args);
																			print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																			run prog
				|{label;instr="BRANCH";args} -> print_triplet courant;
																				branch (List.hd args);
																				print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																				run prog
				|{label;instr="BRANCHIFNOT";args} -> print_triplet courant;
																						 branchifnot (List.hd args);
																						 print_string "-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																						 run prog
				|{label;instr="PUSH";_} -> print_triplet courant;
																	 push ();
																	 print_string "\t\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																	 run prog
				|{label;instr="POP";_} -> print_triplet courant;
																	pop ();
																	print_string "\t\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																	run prog
				|{label;instr="ACC";args} -> print_triplet courant;
																		 acc (int_of_string(List.hd args));
																		 print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																		 run prog
				|{label;instr="ENVACC";args} -> print_triplet courant;
																				envacc (int_of_string(List.hd args));
																				print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																				run prog
				|{label;instr="CLOSURE";args} -> print_triplet courant;
																				 closure (List.hd args) (int_of_string (List.nth args 1));
																				 print_string "-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																				 run prog
				|{label;instr="CLOSUREREC";args} -> print_triplet courant;
				 																 closure_rec (List.hd args) (int_of_string (List.nth args 1));
																				 print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																				 run prog
				|{label;instr="OFFSETCLOSURE";args} -> print_triplet courant;
																				 offset_closure ();
																			 	 print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																	 			 run prog
				|{label;instr="APPLY";args} -> print_triplet courant;
																			 apply (int_of_string (List.hd args));
																			 print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																			 run prog
				|{label;instr="RETURN";args} -> print_triplet courant;
																				return (int_of_string (List.hd args));
																				print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																				run prog
				|{label;instr="GRAB";args} -> print_triplet courant;
																			grab (int_of_string (List.hd args));
																			print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																			run prog
				|{label;instr="RESTART";args} -> print_triplet courant;
																				 restart ();
																				 print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																				 run prog
				|{label;instr="APPTERM";args} -> print_triplet courant;
																				 appterm (int_of_string (List.hd args)) (int_of_string (List.nth args 1));
				  														   print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
	 																		   run prog
				|{label;instr="PUSHTRAP";args} -> print_triplet courant;
																			 	 	pushtrap (List.hd args);
																 				 	print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																 	 			 	run prog
				|{label;instr="POPTRAP";args} -> print_triplet courant;
																 				 poptrap ();
																 				 print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																 				 run prog
				|{label;instr="RAISE";args} -> print_triplet courant;
																 			 raisee ();
																 			 print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_string " trap_sp="; print_int !trap_sp;print_newline ();
																 			 run prog
				|{label;instr="MAKEBLOCK";args} -> print_triplet courant;
																			makeblock (int_of_string (List.hd args));
				  													  print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_newline ();
	 																		run prog
				|{label;instr="GETFIELD";args} -> print_triplet courant;
																		 getfield (int_of_string (List.hd args));
				  													 print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_newline ();
	 																	 run prog
				|{label;instr="VECTLENGTH";_} -> print_triplet courant;
																			 vectlength ();
				  													   print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_newline ();
	 																		 run prog
				|{label;instr="GETVECTITEM";_} -> print_triplet courant;
																			  getvectitem ();
				  													    print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_newline ();
	 																		  run prog
				|{label;instr="SETFIELD";args} -> print_triplet courant;
																			  setfield (int_of_string (List.hd args));
				  													    print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_newline ();
	 																		  run prog
				|{label;instr="SETVECTITEM";_} -> print_triplet courant;
																			  setvectitem ();
				  													    print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_newline ();
	 																		  run prog
				|{label;instr="ASSIGN";args} -> print_triplet courant;
																			  assign (int_of_string (List.hd args));
				  													    print_string "\t-> pc=";print_int !pc;print_string " accu=";print_mlvalue !accu;print_string " stack=[";print_list_aux !stack;print_string "] env=";print_mlvalue !env;print_string " extra_args="; print_int !extra_args;print_newline ();
	 																		  run prog
				|{label;instr="STOP";_} -> print_triplet courant;
																	 print_newline();
																	 print_string "----------------------------------";print_newline();
																	 print_string "Res :";print_mlvalue !accu;print_newline();
																	 print_string "----------------------------------";print_newline();
																	 stop ()
				| _ -> failwith "commande inconnue"
		in run !prog;;
