objects = avl_tree.o main.o 

all: compile

compile: main

run: compile 
	./main

main: $(objects)
	gcc $(objects) -o main

main.o: avl_tree.h
avl_tree.o: avl_tree.h

clean:
	rm -f *.o main

zip:
	zip -r AVLTREE *.c *.h Makefile