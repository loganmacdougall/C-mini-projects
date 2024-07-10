CONTRACT = search
COMPILER = gcc
CSTD = --std=c18

COMP = $(COMPILER) $(CSTD)
MAIN = ../../CI/objects/$(CONTRACT)/$(CONTRACT)M.o

all : $(CONTRACT) dfs bfs

$(CONTRACT) : $(CONTRACT).o queue.o array_list.o $(MAIN)
	$(COMP) $(MAIN) queue.o array_list.o $(CONTRACT).o -o $(CONTRACT)

dfs : $(CONTRACT).o queue.o array_list.o dfsM.o
	$(COMP) dfsM.o queue.o array_list.o $(CONTRACT).o -o dfs

bfs : $(CONTRACT).o queue.o array_list.o bfsM.o
	$(COMP) bfsM.o queue.o array_list.o $(CONTRACT).o -o bfs

$(CONTRACT).o : bintree.c bintree.h
	$(COMP) -c -Ilib bintree.c -o $(CONTRACT).o

queue.o : lib/queue.c lib/queue.h
	$(COMP) -c -Ilib lib/queue.c -o queue.o

array_list.o : lib/array_list.c lib/array_list.h
	$(COMP) -c -Ilib lib/array_list.c -o array_list.o
