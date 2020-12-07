objects = bstree.o main.o 

all: compile

compile: main

run: compile 
	./main

main: $(objects)
	gcc $(objects) -o main

main.o: bstree.h
bstree.o: bstree.h

clean:
	rm -f *.o main

zip:
	zip -r main *.c *.h Makefile