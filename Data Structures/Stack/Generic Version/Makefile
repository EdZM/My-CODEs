objects = stack.o main.o

all: compile

compile: main

run: compile 
	./main


main: $(objects)
	gcc $(objects) -o main

stack.o: stack.h
main.o: stack.h

clean:
	rm -f *.o main

zip:
	zip -r stack *.c *.h Makefile
