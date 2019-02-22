CC=ocamlc
MODULE=str.cma

all :
	$(CC) $(MODULE) -o parser parser.ml #ajout du module Str pour les regexp
	./parser test.txt

clean :
	rm -rf parser.cmi
	rm -rf parser.cmo
	rm -rf parser
