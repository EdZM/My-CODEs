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

void inserir(ARVORE** arvore, int chave);
void remover(ARVORE** arvore, int chave);
void busca(ARVORE* arvore, int chave);

void impressao_em_ordem(NODE* node);
void impressao_pre_ordem(NODE* node);
void impressao_pos_ordem(NODE* node);


void free_tree(ARVORE** arvore);



#endif
