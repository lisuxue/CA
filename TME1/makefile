all :
	ocamlyacc parser.mly
	ocamllex lexer.mll
	ocamlc -c ast.ml parser.mli
	ocamlc -c lexer.ml
	ocamlc -c parser.ml
	ocamlc parser.cmo lexer.cmo eval.ml ast.ml
clean : 
	rm -rf a.out ast.cmi ast.cmo lexer.cmi lexer.cmo lexer.ml parser.cmi parser.cmo parser.ml parser.mli
	