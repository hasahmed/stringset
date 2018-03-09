CC = gcc
#CFLAGS = -g -Wall
CFLAGS = -c -g -Wall
LDFLAGS = -g


EXE=test
GRIND_CMD=valgrind --leak-check=yes ./$(EXE)
SERVER_GRIND=servertest.sh




OBJS = stringset.o main.o strll.o
stringset_test : $(OBJS)
	@echo "Compiling..."
	@$(CC) $(LDFLAGS) -o $(EXE) \
	$(OBJS)
	@echo "Done"

run : stringset_test
	@echo "Running...\n"
	@./$(EXE)
	@echo "\n...finished"


grind : $(EXE)
	$(GRIND_CMD)

servergrind : stringset_test
	@./$(SERVER_GRIND) &
	@./$(EXE) && sleep 10s ; cat grind.log


stringset.o : stringset.c stringset.h
	@echo "Compiling..."
	@$(CC) $(CFLAGS) stringset.c

main.o : main.c
	@echo "Compiling..."
	@$(CC) $(CFLAGS) main.c


strll.o : strll.c
	@echo "Compiling..."
	@$(CC) $(CFLAGS) strll.c

# util.o : util.c
# 	@echo "Compiling..."
# 	@$(CC) $(CFLAGS) util.c

clean :
	@echo "Cleaning..."
	@rm -rf *.o $(EXE) *.dSYM
	@echo "Done"
