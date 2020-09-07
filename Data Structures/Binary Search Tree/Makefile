OPTIMIZER=-O3

MAIN_NAME=BSTREE
MAIN_OBJ=main.o
OBJ1=bstree.o

MAINCFILE=./src/main.c
CFILE1=./src/bstree.c
HFILE1=./include/bstree.h
TESTFILE=./tests/1.in

compile: main

run: compile 
	@#valgrind ./$(MAIN_NAME)
	@#valgrind ./$(MAIN_NAME) < $(TESTFILE)
	@./$(MAIN_NAME) < $(TESTFILE)


all: compile

main: *.o # uses all .o files previously generated 
	gcc $(OPTIMIZER) *.o -o $(MAIN_NAME)


$(MAIN_OBJ): $(MAINCFILE) $(HFILE1) 
	gcc $(OPTIMIZER) -c $(MAINCFILE) -o $(MAIN_OBJ)

$(OBJ1): $(CFILE1) $(HFILE1)
	gcc $(OPTIMIZER) -c $(CFILE1) -o $(OBJ1)


clean:
	rm -f *.o $(MAIN_NAME)

zip:
	zip -r $(MAIN_NAME) include src Makefile

