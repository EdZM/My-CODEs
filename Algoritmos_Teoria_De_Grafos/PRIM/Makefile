all: clean compile clean

compile: main.o mgrafo.o fila_prioridade.o prim.o
	@gcc -o lab4_graf_MST main.o mgrafo.o fila_prioridade.o prim.o -std=c99

main.o:
	@gcc -c main.c -std=c99

mgrafo.o:
	@gcc -c mgrafo.c -std=c99

prim.o:
	@gcc -c prim.c -std=c99

fila_prioridade.o:
	@gcc -c fila_prioridade.c -std=c99

clean:
	@find -name '*~' | xargs rm -rf {}
	@find -name '*.o' | xargs rm -rf {}

run:
	@./lab4_graf_MST

zip:
	zip -r lab4_graf_MST *.c *.h Makefile
