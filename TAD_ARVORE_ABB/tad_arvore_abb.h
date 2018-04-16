#ifndef TAD_ARVORE_ABB_H
#define TAD_ARVORE_ABB_H

typedef struct node{

	int elemento;
	struct node* esquerda;
	struct node* direita;


}NODE;

typedef struct arvore{

	NODE* raiz;

} ARVORE;


//functions
ARVORE* criar_arvore();
void inserir(ARVORE* arvore, int chave);
void remover(ARVORE* arvore, int chave);
void free_tree(ARVORE** arvore);



#endif
