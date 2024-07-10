EXE = simulation
COMPILER = gcc
CSTD = --std=c18 -lpthread

COMP = $(COMPILER) $(CSTD)
MAIN = ${EXE}.o

$(EXE) : $(MAIN) heap.o queue.o array_list.o hero.o location.o world.o
	$(COMP) heap.o queue.o array_list.o hero.o location.o world.o $(MAIN) -o $(EXE)

$(MAIN) : $(EXE).c $(EXE).h
	$(COMP) -g -c -Ilib $(EXE).c -o $(MAIN)

world.o : world.c world.h
	$(COMP) -g -c -Ilib world.c -o world.o

hero.o : hero.c hero.h
	$(COMP) -g -c -Ilib hero.c -o hero.o

location.o : location.c location.h
	$(COMP) -g -c -Ilib location.c -o location.o

heap.o : lib/heap.c lib/heap.h
	$(COMP) -g -c -Ilib lib/heap.c -o heap.o

queue.o : lib/queue.c lib/queue.h
	$(COMP) -g -c -Ilib lib/queue.c -o queue.o

array_list.o : lib/array_list.c lib/array_list.h
	$(COMP) -g -c -Ilib lib/array_list.c -o array_list.o

clean :
	rm queue.o array_list.o heap.o hero.o location.o world.o $(MAIN) $(EXE)
	rm level_alive level_dead
	rm power_alive power_dead
	rm startegy_alive startegy_dead
	rm subtlety_alive subtlety_dead
	rm charm_alive charm_dead
