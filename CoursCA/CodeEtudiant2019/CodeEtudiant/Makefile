# Main directories

BIN=bin
OBJ=obj
INCLUDE=include
SRC=src
TMP=tmp
LIB_PATH=lib
EX=examples
C=c
CP=cpp

# Sources directories

UTL=utl
ASM=asm
BASE=base
PARSE=parsing
MAIN=mains

SRC_BASE=$(SRC)/$(BASE)
SRC_PARSE=$(SRC)/$(PARSE)
SRC_UTL=$(SRC_PARSE)/$(UTL)
SRC_ASM=$(SRC_PARSE)/$(ASM)

# Commands and Options

UTL_H=utl200.h
ASM_H=asm200.h

CC=gcc
CCMIPS=mips-gcc
CPP=g++
YACC=bison -y
LEX = flex
#YACC=bison

CFLAGS=	-Wall \
	-I$(INCLUDE) \
	-DUTL_H='<$(UTL_H)>' \
	-DASM_H='<$(ASM_H)>' \
	-g 

CFLAGS2= -I$(INCLUDE) \
	-DUTL_H='<$(UTL_H)>' \
	-DASM_H='<$(ASM_H)>' \
	-g 

# Object et source files lists

LOCAL_OBJECTS   = asm_mipslex.o                \
                  asm_mipsyac.o                \
                  asm_ReadMipsAsmFiles.o       \

MAIN_CFILES		= $(foreach d,$(SRC)/$(MAIN)/,$(wildcard $(d)/*.c))
MAIN_CPPFILES		= $(foreach d,$(SRC)/$(MAIN)/,$(wildcard $(d)/*.cpp))
MAIN_CBIN		= $(addprefix $(BIN)/$(C)/,$(notdir $(MAIN_CFILES:%.c=%)))
MAIN_CPPBIN		= $(addprefix $(BIN)/$(CP)/,$(notdir $(MAIN_CPPFILES:%.cpp=%)))

UTL_CFILES		= $(foreach d,$(SRC_UTL),$(wildcard $(d)/*.c))
UTL_OBJECTS		= $(addprefix $(OBJ)/$(UTL)/,$(notdir $(UTL_CFILES:%.c=%.o)))

ASM_CFILES		= $(foreach d,$(SRC_ASM),$(wildcard $(d)/*.c))
ASM_OBJECTS		= $(addprefix $(OBJ)/$(ASM)/,$(notdir $(ASM_CFILES:%.c=%.o)))

BASE_CFILES		= $(foreach d,$(SRC_BASE),$(wildcard $(d)/*.cpp))
BASE_OBJECTS		= $(addprefix $(OBJ)/$(BASE)/,$(notdir $(BASE_CFILES:%.cpp=%.o)))

PARSE_CFILES		= asm_mipsyac.c asm_mipslex.c
PARSE_OBJECTS		= $(addprefix $(OBJ)/$(PARSE)/,$(notdir $(PARSE_CFILES:%.c=%.o)))

HEADER_FILES 		= $(foreach d,$(INCLUDE)/,$(wildcard $(d)/*.h))

EX_CFILES		= $(foreach d,$(SRC)/$(EX)/,$(wildcard $(d)/*.c))
EX_SFILES		= $(addprefix $(TMP)/$(EX)/,$(notdir $(EX_CFILES:%.c=%.s)))

LIB 			= $(UTL_OBJECTS) $(ASM_OBJECTS) $(PARSE_OBJECTS) $(BASE_OBJECTS)



# Rules to make the world 

.PHONY : all lib clean


all: $(LIB)  $(MAIN_CBIN) $(MAIN_CPPBIN) 


lib: $(LIB_PATH)/libparsing.a 

$(LIB_PATH)/libparsing.a : $(UTL_OBJECTS) $(ASM_OBJECTS) $(PARSE_OBJECTS) $(BASE_OBJECTS)
	@mkdir -p lib
	ar cr $@ $^
	ranlib $@

$(BIN)/$(C)/% : $(SRC)/$(MAIN)/%.c 
	@mkdir -p $(BIN)/$(C)/
	@mkdir -p $(TMP)
	$(CPP) $(CFLAGS) -o $@ $^ 

$(BIN)/$(CP)/% : $(SRC)/$(MAIN)/%.cpp $(LIB_PATH)/libparsing.a
	@mkdir -p $(BIN)/$(CP)/
	@mkdir -p $(TMP)
	$(CPP) $(CFLAGS) -std=c++11 -o $@ $< -L$(LIB_PATH) -lparsing

#	$(CPP) $(CFLAGS)mv $(SRC_PARSE)/asm_mips.lex.c asm_mipslex.c -o $(BIN)/$@ $^

$(OBJ)/$(BASE)/%.o : $(SRC_BASE)/%.cpp  $(INCLUDE)/%.h
	@mkdir -p  $(OBJ)/$(BASE)
	$(CPP) $(CFLAGS) -std=c++11 -c -o $@ $<

## All this stuff is useful for parsing asm mips source, it comes from an existing project

$(OBJ)/$(UTL)/%.o : $(SRC_UTL)/%.c 
	@mkdir -p $(OBJ)/$(UTL)
	$(CC) $(CFLAGS2) --no-warnings -c -o $@ $<

$(OBJ)/$(ASM)/%.o : $(SRC_ASM)/%.c
	@mkdir -p  $(OBJ)/$(ASM)
	$(CC) $(CFLAGS) -c -o $@ $<


$(OBJ)/$(PARSE)/asm_mipsyac.o : $(SRC_PARSE)/asm_mipsyac.cpp
	@mkdir -p $(OBJ)/$(PARSE)
	$(CPP) $(CFLAGS2) -E -c -o $@.c $<
	$(CPP) $(CFLAGS2) --no-warnings -std=c++11 -c -o $@ $<

$(OBJ)/$(PARSE)/%.o : $(SRC_PARSE)/%.c
	@mkdir -p $(OBJ)/$(PARSE)
	$(CC) $(CFLAGS2) --no-warnings -c -o $@ $<

$(SRC_PARSE)/asm_mipsyac.cpp $(INCLUDE)/asm_mipsyac.h : $(SRC_PARSE)/asm_mips.yac
	cd $(SRC_PARSE) && $(YACC) -d -p asm_mips asm_mips.yac
	cp $(SRC_PARSE)/y.tab.c $@
	cp $(SRC_PARSE)/y.tab.h $(INCLUDE)/asm_mipsyac.h

$(SRC_PARSE)/asm_mipslex.c : $(INCLUDE)/asm_mipsyac.h $(SRC_PARSE)/asm_mips.lex
	$(LEX) -Pasm_mips -o$@ $(SRC_PARSE)/asm_mips.lex
	#mv asm_mips.lex.c asm_mipslex.c


# Project managment rules

clean :
	rm -rf $(OBJ) $(BIN) $(TMP) $(LIB_PATH)
#eviter de recompiler les choses qui ne bouge pas

# EVITER de detruire les fichiers produits par Lex/Yacc pour éviter pb de compatibilité de version 
	#rm -f $(SRC_PARSE)/asm_mipsyac.c* $(INCLUDE)/asm_mipsyac.h $(SRC_PARSE)/asm_mipslex.c $(SRC_PARSE)/asm_mips.tab.*ac 
	#rm -f lex.asm_mips.c



