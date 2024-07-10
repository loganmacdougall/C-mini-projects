CONTRACT = bintree
COMPILER = gcc
CSTD = "--std=c18"

COMP = $(COMPILER) $(CSTD)
MAIN = ../../CI/objects/$(CONTRACT)/$(CONTRACT)M.o

all: $(CONTRACT) intree pretree posttree revtree

$(CONTRACT) : $(CONTRACT).o $(MAIN)
	$(COMP) $(MAIN) $(CONTRACT).o -o $(CONTRACT)

intree : $(CONTRACT).o intreeM.o
	$(COMP) intreeM.o $(CONTRACT).o -o intree

pretree : $(CONTRACT).o pretreeM.o
	$(COMP) pretreeM.o $(CONTRACT).o -o pretree

posttree : $(CONTRACT).o posttreeM.o
	$(COMP) posttreeM.o $(CONTRACT).o -o posttree

revtree : $(CONTRACT).o revtreeM.o
	$(COMP) revtreeM.o $(CONTRACT).o -o revtree

$(CONTRACT).o : $(CONTRACT).c $(CONTRACT).h
	$(COMP) -c $(CONTRACT).c
