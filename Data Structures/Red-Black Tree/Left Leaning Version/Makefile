objects = ll_rbtree.o main.o 

all: compile

compile: main

run: compile 
	./main

main: $(objects)
	gcc $(objects) -o main

main.o: ll_rbtree.h
ll_rbtree.o: ll_rbtree.h

clean:
	rm -f *.o main

zip:
	zip -r LL_RBTree *.c *.h Makefile
