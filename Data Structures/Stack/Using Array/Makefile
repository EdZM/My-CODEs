MAIN_NAME=stack
MAIN_OBJ=main.o
OBJ1=stack.o

MAINCFILE=main.c
CFILE1=stack.c
HFILE1=stack.h

objects = $(MAIN_OBJ) $(OBJ1)

all: compile

compile: main

run: compile 
	./$(MAIN_NAME)


main: $(objects)
	gcc $(objects) -o $(MAIN_NAME)

$(MAIN_OBJ): $(MAINCFILE) $(HFILE1) 
	gcc -c $(MAINCFILE) -o $(MAIN_OBJ)

$(OBJ1): $(CFILE1) $(HFILE1)
	gcc -c $(CFILE1) -o $(OBJ1)

clean:
	rm -f *.o $(MAIN_NAME)

zip:
	zip -r $(MAIN_NAME) include src Makefile
