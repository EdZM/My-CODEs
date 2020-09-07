COMPILER=gcc
OPTIMIZER=-O3

MAIN_NAME=STACK
MAIN_OBJ=main.o
OBJ1=stack.o

MAINCFILE=./src/main.c
CFILE1=./src/stack.c
HFILE1=./include/stack.h
TESTFILE=./tests/1.in

compile: main

run: compile 
	@#valgrind ./$(MAIN_NAME)
	@#valgrind ./$(MAIN_NAME)
	@./$(MAIN_NAME)


all: compile

main: $(MAIN_OBJ) $(OBJ1) 
	gcc $(OPTIMIZER) $(MAIN_OBJ) $(OBJ1) -o $(MAIN_NAME)


$(MAIN_OBJ): $(MAINCFILE) $(HFILE1) 
	gcc $(OPTIMIZER) -c $(MAINCFILE) -o $(MAIN_OBJ)

$(OBJ1): $(CFILE1) $(HFILE1)
	gcc $(OPTIMIZER) -c $(CFILE1) -o $(OBJ1)


clean:
	rm -f *.o $(MAIN_NAME)

zip:
	zip -r $(MAIN_NAME) include src Makefile

