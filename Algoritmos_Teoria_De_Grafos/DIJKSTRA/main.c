#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"
#include "dijkstra.h"

int main (int argc, char *argv[]) {
	int i, vert, arest, x, y, p, ini, fim;
	int *pred;
	GRAFO *grafo;

	scanf("%d %d", &vert, &arest);
	grafo = criar_grafo(vert);

	for (i = 0; i < arest; ++i) {
		scanf("%d %d %d", &x, &y, &p);
		inserir_aresta(grafo, x, y, p);
	}
	while (scanf("%d %d", &ini, &fim) != EOF) {
		pred = obter_predecessores(grafo, ini, fim);
		imprimir_menor_caminho(pred, fim, fim);
		printf("\n");
	}

	liberar_matriz(&grafo);
	free(pred);
	return 0;
}
