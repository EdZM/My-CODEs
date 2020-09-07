#ifndef HEAP_H
#define HEAP_H

#define TAM 100001

typedef struct tupla {
	int custo, vert;
} TUPLA;

typedef struct heap_estatico {
        TUPLA *vetor[TAM];
        int fim;
} HEAP;

HEAP *criar_heap();
TUPLA *criar_tupla(int, int);
int inserir_tupla(HEAP *, TUPLA *);
TUPLA *remover_tupla(HEAP *);
int cheia_heap(HEAP *);
int vazia_heap(HEAP *);
void atualizar_tupla(HEAP *, int, int);
int obter_custo(HEAP *, int);
TUPLA *raiz_heap(HEAP *);
void excluir_heap(HEAP **);

#endif
