objects = skiplist.o main.o 

all: compile

compile: main

run: compile 
	#./main < ./tests/1.in
	#./main < case.in > case.out
	./main

main: $(objects)
	gcc $(objects) -o main

main.o: skiplist.h
skiplist.o: skiplist.h

clean:
	rm -f *.o main

zip:
	zip -r Skiplist *.c *.h Makefile