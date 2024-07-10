CONTRACT = heap
COMPILER = gcc
CSTD = "--std=c18"

COMP = $(COMPILER) $(CSTD)
MAIN = ../../CI/objects/$(CONTRACT)/${CONTRACT}M.o

all : $(CONTRACT) rheap

$(CONTRACT) : $(CONTRACT).o array_list.o $(MAIN)
	$(COMP) $(MAIN) array_list.o $(CONTRACT).o -o $(CONTRACT)

rheap : $(CONTRACT).o array_list.o rheapM.o
	$(COMP) rheapM.o array_list.o $(CONTRACT).o -o rheap

$(CONTRACT).o : ${CONTRACT}.c ${CONTRACT}.h
	$(COMP) -g -c -Ilib ${CONTRACT}.c -o $(CONTRACT).o

array_list.o : lib/array_list.c lib/array_list.h
	$(COMP) -g -c -Ilib lib/array_list.c -o array_list.o
