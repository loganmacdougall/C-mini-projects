COMPILER = gcc
CSTD = --std=c18

MAIN = ../../CI/objects/linked_list/linkedM.o

linked_list : linked_list.o
	$(COMPILER) $(CSTD) $(MAIN) linked_list.o -o linked_list

linked_list.o : linked_list.c linked_list.h
	$(COMPILER) $(CSTD) -c linked_list.c
