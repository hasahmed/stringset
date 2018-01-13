CC = gcc
CFLAGS = -I$(HOME)/CUnit/include
LDFLAGS = -L$(HOME)/CUnit/lib
EXE = runtests

OBJS = node.o stringset.o util.o tests.o
SRCS = ../node.c ../stringset.c ../util.c tests.c

$(EXE) : objs
	$(CC) $(LDFLAGS) $(CFLAGS) -o $(EXE) $(OBJS) -lcunit

objs : $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS) 

clean :
	rm -f $(EXE) *.o
