objects = treap.o queue.o main.o 

all: compile

compile: main

run: compile 
	./main

main: $(objects)
	gcc $(objects) -o main

main.o: treap.h
treap.o: treap.h
queue.o: queue.h

clean:
	rm -f *.o main

zip:
	zip -r Treap *.c *.h Makefile