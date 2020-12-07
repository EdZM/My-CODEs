objects = main.o gen_list.o

all: compile

compile: main

main: $(objects)
	gcc $(objects) -o main

gen_list.o: gen_list.h # lembrando que isso representa gen_list.o: gen_list.c gen_list.h (gen_list de baixo) gcc -c gen_list.c -o gen_list.o
main.o: gen_list.h

run: compile
	./main

clean:
	rm -f main *.o