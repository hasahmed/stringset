CC = gcc
CFLAGS = -g -o0 -Wall
LDFLAGS = -g


EXE = stringset_test
OBJS = stringset.o main.o


stringset_test : $(OBJS)
	$(CC) $(LDFLAGS) -o $(EXE) \
	stringset.o \
	main.o

grind : stringset_test
	valgrind --leak-check=yes ./$(EXE)

stringset.o : stringset.c stringset.h
	$(CC) -c -g stringset.c

main.o : main.c
	$(CC) -c -g main.c


clean :
	rm -rf *.o $(EXE) *.dSYM
