CC=ocamlc
MODULE=str.cma
#https://zestedesavoir.com/billets/2081/la-compilation-en-ocaml-avec-ocamlc-et-ocamlopt/

all :
	$(CC) $(MODULE) -c main.ml parser.ml #ajout du module Str pour les regexp
	$(CC) -c -o instr instr.ml
	
	./instr tests/unary_funs/fun3.txt

clean :
	rm -rf parser.cmi
	rm -rf parser.cmo
	rm -rf parser
	
	

