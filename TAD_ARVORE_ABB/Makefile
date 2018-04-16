all: clean compile clean

compile: main.o tad_arvore_abb.o
	@gcc -o TAD_ARVORE_ABB main.o tad_arvore_abb.o  

main.o:
	@gcc -c main.c

tad_arvore_abb.o:
	@gcc -c tad_arvore_abb.c

clean:
	@find -name '*~' | xargs rm -rf {}
	@find -name '*.o' | xargs rm -rf {}


run:
	@./TAD_ARVORE_ABB

zip:
	zip -r TAD_ARVORE_ABB *.c* .h Makefile

