objects = skiplist.o P1_Alg-I.o 

all: compile

compile: main

run: compile 
	./main < ./1.in
	#./main

main: $(objects)
	gcc $(objects) -o main

P1_Alg-I.o: skiplist.h
skiplist.o: skiplist.h

clean:
	rm -f *.o main

zip:
	zip -r T5_Alg-I *.c *.h Makefile