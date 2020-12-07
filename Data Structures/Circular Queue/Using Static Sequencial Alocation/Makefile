objects = queue.o main.o

all: compile

compile: main


main: $(objects)
	gcc $(objects) -o main

main.o: queue.h # igual fazer: main.o: main.c queue.h (linha de baixo) gcc -c main.c -o main.o
queue.o: queue.h 

run:
	./main

clean:
	rm -f main *.o

zip:
	zip -r queue *.c *.h Makefile

