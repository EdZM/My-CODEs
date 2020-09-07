all: clean compile clean

compile: main.o mgrafo.o lgrafo.o
	@gcc -std=c99 -o lab1grafos main.o mgrafo.o lgrafo.o 
	
	
main.o:
	@gcc -std=c99 -c main.c 

mgrafo.o:
	@gcc -std=c99 -c mgrafo.c 

lgrafo.o:
	@gcc -std=c99 -c lgrafo.c 

clean:
	@find -name '*~' | xargs rm -rf {}
	@find -name '*.o' | xargs rm -rf {}

run:
	@./lab1grafos

zip:
	zip -r lab1grafos *.c *.h Makefile
