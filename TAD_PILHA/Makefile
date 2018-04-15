all: clean compile clean

compile: main.o tad_pilha.o 
	@gcc -o TAD_PILHA main.o tad_pilha.o 

main.o:
	@gcc -c main.c

tad_pilha.o:
	@gcc -c tad_pilha.c

clean:
	@find -name '*~' | xargs rm -rf {}
	@find -name '*.o' | xargs rm -rf {}

run:
	@valgrind ./TAD_PILHA

zip:
	zip -r TAD_PILHA *.c *.h Makefile
