CC=ocamlc
MODULES=str.cma parser.ml minizam.ml
MAIN=main_direct
MAINDETAIL=main_detail
NOAPPTERM=main_detail_no_appterm

all : direct

direct :
	$(CC) -o $(MAIN) $(MODULES) $(MAIN).ml

detail :
	$(CC) -o $(MAINDETAIL) $(MODULES) $(MAINDETAIL).ml

no_appterm :
		$(CC) -o $(NOAPPTERM) $(MODULES) $(NOAPPTERM).ml

clean :
	rm -rf *.cma
	rm -rf *.cmi
	rm -rf *.cmo
	rm -rf $(MAIN)
	rm -rf $(MAINDETAIL)
	rm -rf $(NOAPPTERM)
