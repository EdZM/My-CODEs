all: clean compile clean

compile: main.o tad_fila.o
	@gcc -o TAD_FILA main.o tad_fila.o

main.o:
	@gcc -c main.c

tad_fila.o:
	@gcc -c tad_fila.c

clean:
	@find -name '*~' | xargs rm -rf {}
	@find -name '*.o' | xargs rm -rf {}


run:
	@valgrind ./TAD_FILA

zip:
	zip -r TAD_FILA *.c* .h Makefile

