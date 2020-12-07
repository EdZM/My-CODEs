objects = skiplist.o P1_Alg-I.o 

all: compile

compile: main

run: compile 
	@#./main < ./tests/1.in > 1.out
	@#./main < ./tests/2.in > 2.out
	@#./main < ./tests/3.in > 3.out
	@#./main < ./tests/4.in > 4.out
	@#./main < ./tests/5.in > 5.out
	./main < 1.in
	@#./main < 4.in
	@#./main

main: $(objects)
	gcc $(objects) -o main

P1_Alg-I.o: skiplist.h
skiplist.o: skiplist.h

clean:
	rm -f *.o main

zip:
	zip -r P1_Alg-I *.c *.h Makefile