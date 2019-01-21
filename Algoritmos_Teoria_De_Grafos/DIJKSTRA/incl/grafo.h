#ifndef GRAFO_H
#define GRAFO_H

#include "grafo.h"

typedef struct grafo GRAFO;

struct grafo {
	int n;
	int **matriz;
};

GRAFO *criar_grafo(int);
void inserir_aresta(GRAFO *, int, int, int);
void liberar_matriz(GRAFO **);

#endif
