#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include "grafo.h"
#include "heap.h"

#define FALSE 0
#define TRUE 1

int *obter_predecessores(GRAFO *g, int ini, int fim) {
	int i, vert_atual;
	int *pred = NULL, *dist = NULL, *visit = NULL;
	HEAP *Q = criar_heap();

	pred = (int *) malloc(sizeof(int) * g->n);
	dist = (int *) malloc(sizeof(int) * g->n);
	visit = (int *) malloc(sizeof(int) * g->n);

	for (i = 0; i < g->n; ++i) {
		pred[i] = -1;
		dist[i] = INT_MAX;
		visit[i] = FALSE;
		inserir_tupla(Q, criar_tupla(i, INT_MAX));
	}

	dist[ini] = 0;
	visit[ini] = TRUE;
	atualizar_tupla(Q, ini, 0);

	while (!vazia_heap(Q)) {
		TUPLA *min = remover_tupla(Q);
		vert_atual = min->vert;
		visit[vert_atual] = TRUE;

		for (i = 0; i < g->n; ++i) {
			if (g->matriz[vert_atual][i] != -1 && !visit[i]) {
				if (dist[i] > dist[vert_atual] + g->matriz[vert_atual][i]) {
					dist[i] = dist[vert_atual] + g->matriz[vert_atual][i];
					pred[i] = vert_atual;
					atualizar_tupla(Q, i, dist[vert_atual] + g->matriz[vert_atual][i]);
				}
			}
		}
		free(min);
	}

	free(dist);
	free(visit);
	excluir_heap(&Q);

	pred[ini] = -2;

	return pred;
}

int imprimir_menor_caminho(int *pred, int index, int fim) {
	if (pred[index] == -2) {
		if (index != fim)
			printf("%d", index);
		return 1;
	}
	if (pred[index] == -1)
		return 0;

	int imp = imprimir_menor_caminho(pred, pred[index], fim);
	if (imp) printf(" %d", index);
	return imp;
}
