all: clean compile clean

compile: main.o mgrafo.o dfs.o tad_fila.o
	@gcc -o lab3_graf_Ord_top main.o mgrafo.o dfs.o tad_fila.o -std=c99

main.o:
	@gcc -c main.c -std=c99

mgrafo.o:
	@gcc -c mgrafo.c -std=c99

tad_fila.o:
	@gcc -c tad_fila.c -std=c99

dfs.o:
	@gcc -c dfs.c -std=c99

clean:
	@find -name '*~' | xargs rm -rf {}
	@find -name '*.o' | xargs rm -rf {}

run:
	@./lab3_graf_Ord_top

zip:
	zip -r lab3_graf_Ord_top *.c *.h Makefile
