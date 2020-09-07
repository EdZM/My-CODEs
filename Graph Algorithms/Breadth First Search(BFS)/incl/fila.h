/*
* =====================================================================================================================
*
*       Filename:  fila.h
*
*    Description:  Arquivo que contem a descrição das funções e elementos do TAD_fila
*				   
*
*         Nome:  Eduardo Zaboto Mirolli 
*         Nº USP:  9778501
*
* =====================================================================================================================
*/

#ifndef FILA_H
#define FILA_H

typedef struct node {
	struct node *proximo;
	int elemento;
} NODE;

typedef struct fila {
	NODE *inicio;
	NODE *fim;
	int tamanho;
} FILA;

FILA *criar_fila();
void enfileirar(FILA *, int);
int frente(FILA *);
void desenfileirar(FILA *);
int vazia(FILA *);
void liberar_fila(FILA **);

#endif
