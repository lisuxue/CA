CC=ocamlc
MODULE=str.cma
#https://zestedesavoir.com/billets/2081/la-compilation-en-ocaml-avec-ocamlc-et-ocamlopt/

all :
	$(CC) $(MODULE) -c parser.ml #ajout du module Str pour les regexp
	$(CC) -c -o main main.ml

	./main tests/unary_funs/fun3.txt

clean :
	rm -rf *.cma
	rm -rf *.cmi
	rm -rf *.cmo
	rm -rf main
