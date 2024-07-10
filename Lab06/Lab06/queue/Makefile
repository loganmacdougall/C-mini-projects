CONTRACT = queue
COMPILER = gcc
CSTD = --std=c18

COMP = $(COMPILER) $(CSTD)
MAIN = ../../CI/objects/$(CONTRACT)/$(CONTRACT)M.o

$(CONTRACT) : $(CONTRACT).o array_list.o $(MAIN)
	$(COMP) -g $(MAIN) array_list.o $(CONTRACT).o -o $(CONTRACT)

$(CONTRACT).o : $(CONTRACT).c $(CONTRACT).h
	$(COMP) -g -c $(CONTRACT).c

array_list.o : lib/array_list.c lib/array_list.h
	$(COMP) -g -c -Ilib lib/array_list.c
