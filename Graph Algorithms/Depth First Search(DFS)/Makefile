all: clean compile clean

compile: main.o mgrafo.o dfs.o
	@gcc -o lab2_graf_DFS main.o mgrafo.o dfs.o -std=c99

main.o:
	@gcc -c main.c -std=c99

mgrafo.o:
	@gcc -c mgrafo.c -std=c99

dfs.o:
	@gcc -c dfs.c -std=c99

clean:
	@find -name '*~' | xargs rm -rf {}
	@find -name '*.o' | xargs rm -rf {}

run:
	@./lab2_graf_DFS 

zip:
	zip -r lab2_graf_DFS *.c *.h Makefile
