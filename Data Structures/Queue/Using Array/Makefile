COMPILER=gcc
OPTIMIZER=-O3

MAIN_NAME=QUEUE
MAIN_OBJ=main.o
OBJ1=queue.o

MAINCFILE=main.c
CFILE1=queue.c

HFILE1=queue.h

compile: main

run: compile 
	@#valgrind ./$(MAIN_NAME)
	@./$(MAIN_NAME)


all: compile

main: $(MAIN_OBJ) $(OBJ1) 
	$(COMPILER) $(OPTIMIZER) $(MAIN_OBJ) $(OBJ1) -o $(MAIN_NAME)


$(MAIN_OBJ): $(MAINCFILE) $(HFILE1) 
	$(COMPILER) $(OPTIMIZER) -c $(MAINCFILE) -o $(MAIN_OBJ)

$(OBJ1): $(CFILE1) $(HFILE1)
	$(COMPILER) $(OPTIMIZER) -c $(CFILE1) -o $(OBJ1)


clean:
	rm -f *.o $(MAIN_NAME)

zip:
	zip -r $(MAIN_NAME) ./src/*.c ./include/*.h Makefile

