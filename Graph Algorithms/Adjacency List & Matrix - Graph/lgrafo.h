/*
 * =====================================================================================================================
 *
 *       Filename:  mgrafo.h
 *
 *    Description:  Arquivo contendo as assinaturas de todas as funções que serão feitas em cima da lista de adjacencia
 *
 *         Nome:  Eduardo Zaboto Mirolli 
 *         Nº USP:  9778501
 *
 * =====================================================================================================================
 */

#ifndef LGRAFO_H
#define LGRAFO_H


typedef struct l_grafo L_GRAFO;
typedef struct node NODE;
typedef struct arco ARCO;

struct l_grafo {
        struct node **vetor; //indica um vetor de nós. Cada posição( vertice) desse vetor está associada com outras posições(no caso vertices adjacentes a essa posição)
        int n;
};

struct node { //struct para representar cada nó da lista de adjacencia
        int n_aresta; // indica o numero de arestas
        struct arco *sentinel; 
        struct arco *fim;
};

struct arco { //struct para representar as informações de uma aresta( liga dois vertices ) qualquer 
        int peso; //indica o peso da aresta
        int adj; 
        struct arco *prox; //ponteiro para o proximo arco
};

L_GRAFO *cria_list_graf(int n);
void inserir_aresta_l(L_GRAFO *lgraf , int d, int x, int y , int peso);
void remover_aresta_l(L_GRAFO *lgraf, int d, int x,  int y);
void encontra_min_val_l(L_GRAFO * lgraf, int d);
void transposed_graf_l(L_GRAFO *lgraf, int d);
void imprimir_vert_adjacente_l(L_GRAFO* lgraf, int vert);
void imprimir_grafo_l(L_GRAFO *lgraf);
void free_list_graf(L_GRAFO **lgraf);


#endif