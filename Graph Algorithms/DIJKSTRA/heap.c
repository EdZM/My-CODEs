#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

HEAP *criar_heap() {
	HEAP *novo = (HEAP *) malloc (sizeof(HEAP));
	if (novo != NULL) novo->fim = -1;
	return novo;
}

void swap(TUPLA **vetor, int pos_a, int pos_b) {
	TUPLA *tmp = vetor[pos_a];
	vetor[pos_a] = vetor[pos_b];
	vetor[pos_b] = tmp;
}

void fix_up(HEAP *h) {
	int pos = h->fim;
	while (pos > 0 && h->vetor[pos]->custo < h->vetor[(pos-1)/2]->custo) {
		swap(h->vetor, pos, (pos-1)/2);
		pos = (pos-1)/2;
	}
}

TUPLA *criar_tupla(int vert, int custo) {
	TUPLA *t = (TUPLA *) malloc (sizeof(TUPLA));
	if (t != NULL) {
		t->custo = custo;
		t->vert = vert;
	}
	return t;
}

int inserir_tupla(HEAP *h, TUPLA *t) {
	if (h != NULL && !cheia_heap(h)) {
		h->fim++;
		h->vetor[h->fim] = t;
		fix_up(h); // reestruturar o heap para ser binario
		return 1;
	}
	return 0;
}

void fix_down(HEAP *h) {
        int pos = 0;
        while (pos < h->fim/2) {
                int menor = 2*pos+1; // filho da esquerda
                if ((2*pos+2) <= h->fim) { //filho da direita existe?
                        if (h->vetor[menor]->custo > h->vetor[2*pos+2]->custo)
                                menor++; // filho da direita
                }

                swap(h->vetor, pos, menor);
                pos = menor;
        }
}

TUPLA *remover_tupla(HEAP *h) {
        if (h != NULL && !vazia_heap(h)) {
                TUPLA *ret = h->vetor[0];
                h->vetor[0] = h->vetor[h->fim];
                h->fim--;
                fix_down(h);

                return ret;
        }
	return NULL;
}

void atualizar_tupla(HEAP *h, int vert, int novo_custo) {
	int i;

	for (i = 0; i <= h->fim; i++) {
		if (h->vetor[i]->vert == vert) {
			h->vetor[i]->custo = novo_custo;
			break;
		}
	}

	while (h->vetor[i] != NULL && h->vetor[i]->custo < h->vetor[(i - 1) / 2]->custo) {
		swap(h->vetor, i, (i - 1) / 2);
		i = (i - 1) / 2;
	}
}

int obter_custo(HEAP *h, int vert) {
	int i;
	for (i = 0; i <= h->fim; i++) {
		if (h->vetor[i]->vert == vert)
			return h->vetor[i]->custo;
	}
	return -1;
}

int cheia_heap(HEAP *h) {
	return h->fim == TAM-1;
}

int vazia_heap(HEAP *h) {
	return h->fim == -1;
}

TUPLA *raiz_heap(HEAP *h) {
	return h->vetor[0];
}

void excluir_heap(HEAP **h) {
	int i;
	for (i = 0; i < (*h)->fim; i++)
		free((*h)->vetor[i]);
	free((*h)->vetor);
}
