CC = gcc
#CFLAGS = -g -Wall
CFLAGS = -c -g -Wall
LDFLAGS = -g


EXE = stringset_test
OBJS = stringset.o main.o node.o
GRIND_CMD = valgrind --leak-check=yes ./$(EXE)

SERVER_GRIND=servertest.sh

stringset_test : $(OBJS)
	@echo "Compiling..."
	@$(CC) $(LDFLAGS) -o $(EXE) \
	$(OBJS)
	@echo "Done"

grind : $(EXE)
	$(GRIND_CMD)

servergrind : stringset_test
	@./$(SERVER_GRIND) &


stringset.o : stringset.c stringset.h
	@echo "Compiling..."
	@$(CC) $(CFLAGS) stringset.c

main.o : main.c
	@echo "Compiling..."
	@$(CC) $(CFLAGS) main.c


node.o : node.c
	@echo "Compiling..."
	@$(CC) $(CFLAGS) node.c

clean :
	@echo "Cleaning..."
	@rm -rf *.o $(EXE) *.dSYM
	@echo "Done"
