objects = b_list.o main.o 

all: compile

compile: main

run: compile 
	./main

main: $(objects)
	gcc $(objects) -o main

main.o: b_list.h
b_list.o: b_list.h

clean:
	rm -f *.o main

zip:
	zip -r BackwardList *.c *.h Makefile