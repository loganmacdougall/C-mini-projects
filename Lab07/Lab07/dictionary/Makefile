CONTRACT = dictionary
COMPILER = gcc
CSTD = --std=c18

COMP = $(COMPILER) $(CSTD)
MAIN = ../../CI/objects/$(CONTRACT)/dictM.o

$(CONTRACT) : $(CONTRACT).o bintree.o queue.o array_list.o $(MAIN)
	$(COMP) $(MAIN) bintree.o queue.o array_list.o $(CONTRACT).o -o $(CONTRACT)

$(CONTRACT).o : ${CONTRACT}.c ${CONTRACT}.h
	$(COMP) -c -Ilib ${CONTRACT}.c -o $(CONTRACT).o

bintree.o : lib/bintree.c lib/bintree.h
	$(COMP) -c -Ilib lib/bintree.c -o bintree.o

queue.o : lib/queue.c lib/queue.h
	$(COMP) -c -Ilib lib/queue.c -o queue.o

array_list.o : lib/array_list.c lib/array_list.h
	$(COMP) -c -Ilib lib/array_list.c -o array_list.o
