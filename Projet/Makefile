CC=ocamlc
MODULE=str.cma
#https://zestedesavoir.com/billets/2081/la-compilation-en-ocaml-avec-ocamlc-et-ocamlopt/

all :
	$(CC) $(MODULE) -c parser.ml #ajout du module Str pour les regexp
	$(CC) $(MODULE) parser.cmo -o main main.ml
	 cat tests/exceptions/exn.ml
	 ./main tests/exceptions/exn.txt

clean :
	rm -rf *.cma
	rm -rf *.cmi
	rm -rf *.cmo
	rm -rf main
