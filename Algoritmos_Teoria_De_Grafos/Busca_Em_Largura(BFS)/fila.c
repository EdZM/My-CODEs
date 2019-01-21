/*
* =====================================================================================================================
*
*       Filename:  fila.c
*
*    Description:  Arquivo que contem a implementação das funções do TAD_fila(fila.h)
*				   
*
*         Nome:  Eduardo Zaboto Mirolli 
*         Nº USP:  9778501
*
* =====================================================================================================================
*/

#include <stdlib.h>
#include <stdio.h>

#include "fila.h"

FILA *criar_fila() {
	FILA *f = (FILA *) malloc (sizeof(FILA));
	if (f != NULL) {
		f->inicio = f->fim = NULL;
		f->tamanho = 0;
	}
	return f;
}


//função para inserir um elemento na fila
void enfileirar(FILA *f, int e) {
	if (f != NULL) {
		NODE *n = (NODE *) malloc (sizeof(NODE));
		if (n != NULL) {
			n->proximo = NULL;
			n->elemento = e;
			if (f->tamanho == 0) {
				f->inicio = f->fim = n; 
			} else {
				f->fim->proximo = n;
				f->fim = n;				
			}
			f->tamanho++;
		}
	}
}

//função que apenas retorna o primeiro elemento da fila
int frente(FILA *f) {
	return f->inicio->elemento;
}

//função que retira um elemento da fila (sempre o primeiro)
void desenfileirar(FILA *f) {
	NODE *rem;
	
	if (f->tamanho > 0) {
		rem = f->inicio;
		f->inicio = f->inicio->proximo;
		free(rem);
		f->tamanho--;
	}
}

//função que checa se a fila está vazia, sem elemento algum
int vazia(FILA *f) {
	return (f->tamanho == 0);
}


//funçã que desaloca a fila
void liberar_fila(FILA **f) {
	while ((*f)->tamanho > 0) desenfileirar(*f);
	free(*f);
	*f = NULL;
}
