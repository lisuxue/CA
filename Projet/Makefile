CC=ocamlc
MODULES=str.cma parser.ml minizam.ml
MAIN=main_direct
MAINDETAIL=main_detail

all : direct

direct :
	$(CC) -o $(MAIN) $(MODULES) $(MAIN).ml

detail :
	$(CC) -o $(MAINDETAIL) $(MODULES) $(MAINDETAIL).ml

clean :
	rm -rf *.cma
	rm -rf *.cmi
	rm -rf *.cmo
	rm -rf $(MAIN)
	rm -rf $(MAINDETAIL)
	
