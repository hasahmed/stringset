CC = gcc
CFLAGS = -I/Users/hasankatie/CUnit/include
#LDFLAGS = -L/Users/hasankatie/CUnit/lib
EXE = runtests
VPATH = ../


OBJS = node.o stringset.o util.o tests.o

$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS) -lcunit

clean :
	rm -f $(EXE) *.o

objs : $(OBJS)
