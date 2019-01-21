#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "grafo.h"

GRAFO *criar_grafo(int n) {
	int i, j, **mat = NULL;
	GRAFO *graf = NULL;

	graf = (GRAFO *) malloc (sizeof(GRAFO));
	mat = (int **) malloc (n * sizeof(int *));
	for (i = 0; i < n; i++)
		mat[i] = (int *) malloc (n * sizeof(int));
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			mat[i][j] = -1;
		}
	}

	graf->matriz = mat;
	graf->n = n;
	return graf;
}

void inserir_aresta(GRAFO *grafo, int x, int y, int p) {
	grafo->matriz[x][y] = p;
}

void liberar_matriz(GRAFO **grafo) {
	int i;
	if (*grafo != NULL) {
		for (i = 0; i < (*grafo)->n; i++) free((*grafo)->matriz[i]);
		free((*grafo)->matriz);
		free(*grafo);
		*grafo = NULL;
	}
}
