all: clean compile clean

compile: main.o rbtree.o 
	@gcc -o prog main.o rbtree.o 

main.o:
	@gcc -c main.c

rbtree.o:
	@gcc -c rbtree.c

clean:
	@find -name '*~' | xargs rm -rf {}
	@find -name '*.o' | xargs rm -rf {}

run:
	@./prog

zip:
	zip -r prog *.c *.h Makefile
