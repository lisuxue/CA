CC=ocamlc
MODULES=str.cma parser.ml minizam.ml
MAIN=main_direct
MAINTRACE=main_trace

all : direct

direct :
	$(CC) -o $(MAIN) $(MODULES) $(MAIN).ml

trace :
	$(CC) -o $(MAINTRACE) $(MODULES) $(MAINTRACE).ml

clean :
	rm -rf *.cma
	rm -rf *.cmi
	rm -rf *.cmo
	rm -rf $(MAIN)
	rm -rf $(MAINTRACE)
