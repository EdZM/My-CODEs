objects = bin_tree.o main.o 

all: compile

compile: main

run: compile 
	./main

main: $(objects)
	gcc $(objects) -o main

main.o: bin_tree.h
bin_tree.o: bin_tree.h

clean:
	rm -f *.o main

zip:
	zip -r main *.c *.h Makefile