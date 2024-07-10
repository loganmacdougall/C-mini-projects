CONTRACT = pool
COMPILER = gcc
CSTD = --std=c18 -lpthread

COMP = $(COMPILER) $(CSTD)
MAIN = ${CONTRACT}M.o

$(CONTRACT) : $(CONTRACT).o heap.o queue.o array_list.o $(MAIN)
	$(COMP) $(MAIN) heap.o queue.o array_list.o $(CONTRACT).o -o $(CONTRACT)

$(CONTRACT).o : ${CONTRACT}.c ${CONTRACT}.h
	$(COMP) -g -c -Ilib ${CONTRACT}.c -o $(CONTRACT).o

heap.o : lib/heap.c lib/heap.h
	$(COMP) -g -c -Ilib lib/heap.c -o heap.o

queue.o : lib/queue.c lib/queue.h
	$(COMP) -g -c -Ilib lib/queue.c -o queue.o

array_list.o : lib/array_list.c lib/array_list.h
	$(COMP) -g -c -Ilib lib/array_list.c -o array_list.o
clean :
	rm queue.o array_list.o heap.o pool.o pool
