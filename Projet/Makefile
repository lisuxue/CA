CC=ocamlc
STRMODULE=str.cma

all :
	#$(CC) $(STRMODULE) -c parser.ml #ajout du module Str pour les regexp
	#$(CC) $(STRMODULE) parser.cmo -o main_bis main_bis.ml
	 #cat tests/appterm/fun_appterm.ml
	 #./main tests/appterm/fun_appterm.txt
	$(CC) -o main_bis $(STRMODULE) parser.ml main_bis.ml

clean :
	rm -rf *.cma
	rm -rf *.cmi
	rm -rf *.cmo
	rm -rf main
