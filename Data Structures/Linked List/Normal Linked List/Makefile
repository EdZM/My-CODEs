objects = main.o list.o

all: compile

compile: main

main: $(objects)
	gcc $(objects) -o main

list.o: list.h # lembrando que isso representa lista.o: lista.c lista.h (lista de baixo) gcc -c lista.c -o lista.o
main.o: list.h

run: compile
	./main

clean:
	rm -f main *.o
