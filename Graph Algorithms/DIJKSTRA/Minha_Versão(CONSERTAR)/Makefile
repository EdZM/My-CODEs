all: clean compile clean

compile: main.o mgrafo.o fila_prioridade.o dijkstra.o
	@gcc -O3 -o lab5_graf_dijkstra main.o mgrafo.o fila_prioridade.o dijkstra.o -std=c99

main.o:
	@gcc -O3 -c main.c -std=c99

mgrafo.o:
	@gcc -O3 -c mgrafo.c -std=c99

dijkstra.o:
	@gcc -O3 -c dijkstra.c -std=c99

fila_prioridade.o:
	@gcc -O3 -c fila_prioridade.c -std=c99

clean:
	@find -name '*~' | xargs rm -rf {}
	@find -name '*.o' | xargs rm -rf {}

run:
	@./lab5_graf_dijkstra < 1.in

zip:
	zip -r lab5_graf_dijkstra *.c *.h Makefile
