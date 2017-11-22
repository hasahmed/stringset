CC = gcc
CFLAGS = -g -o0 -Wall
LDFLAGS = -g


EXE = stringset_test
OBJS = stringset.o main.o


stringset_test : $(OBJS)
	@echo "Compiling..."
	@$(CC) $(LDFLAGS) -o $(EXE) \
	stringset.o \
	main.o
	@echo "Done"

grind : stringset_test
	valgrind --leak-check=yes ./$(EXE)

stringset.o : stringset.c stringset.h
	@echo "Compiling..."
	@$(CC) -c -g stringset.c

main.o : main.c
	@echo "Compiling..."
	@$(CC) -c -g main.c


clean :
	@echo "Cleaning..."
	@rm -rf *.o $(EXE) *.dSYM
	@echo "Done"
