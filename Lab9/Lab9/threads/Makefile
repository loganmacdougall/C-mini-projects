CONTRACT = threads
COMPILER = gcc
CSTD = --std=c18 -lpthread

COMP = $(COMPILER) $(CSTD)
MAIN = ${CONTRACT}M.o

all : $(CONTRACT) unsafe safe

$(CONTRACT) : $(CONTRACT).o $(MAIN)
	$(COMP) $(MAIN) $(CONTRACT).o -o $(CONTRACT)

$(CONTRACT).o : ${CONTRACT}.c ${CONTRACT}.h
	$(COMP) -g -c -Ilib ${CONTRACT}.c -o $(CONTRACT).o

unsafe : unsafe.o unsafeM.o
	$(COMP) unsafeM.o unsafe.o -o unsafe

unsafe.o : unsafe.c unsafe.h
	$(COMP) -g -c -Ilib unsafe.c -o unsafe.o

safe : safe.o safeM.o
	$(COMP) safeM.o safe.o -o safe

safe.o : safe.c safe.h
	$(COMP) -g -c -Ilib safe.c -o safe.o
