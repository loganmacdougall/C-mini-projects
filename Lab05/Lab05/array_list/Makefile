COMPILER = gcc
CSTD = --std=c18

MAIN = ../../CI/objects/array_list/arrayM.o

array_list : array_list.o
	$(COMPILER) $(CSTD) -g $(MAIN) array_list.o -o array_list

array_list.o : array_list.c array_list.h
	$(COMPILER) $(CSTD) -g -c array_list.c
