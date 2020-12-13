/*
Nome : Eduardo Zaboto Mirolli  
NºUSP: 9778501

Algoritmos e Estruturas de Dados I- Trabalho 3 - Arvore Vermelho e Preto

---->Programa que realiza operações em uma arvore vermelho e preto
		operações:
				-1)Inserir: Insercao de elementos na arvore 
				-2)Sucessor: Encontrar o sucessor de uma chave escolhida 
				-3)Predecessor: Encontrar o antecessor de uma chave escolhida 
				-4)Maximo: Encontrar a chave da arvore de maior valor 
				-5)Minimo: Encontrar a chave da arvore de menor valor 
				-6)Pre-ordem: Impressao em pre-ordem das chaves existentes a arvore
				-7)Em-ordem: Impressao em ordem das chaves existentes a arvore
				-8)Pos-ordem: Impressao em pos ordem das chaves existentes a arvore
*/

#ifndef RBTREE_H
#define RBTREE_H

typedef int t_chave;

typedef struct no { 
	t_chave chave; 
	int cor;
	struct no *esquerda, *direita, *pai;
	
}no_rb; //Um nó da arvore vermelho e preto

typedef no_rb* t_apontador;
typedef t_apontador t_rbtree; //aponta para a raiz da arvore

void inicializar_arvore(t_rbtree* arvore); 
void inserir(t_apontador* arvore, t_chave chave); 	
t_chave sucessor(t_apontador A , t_chave chave);
t_chave predecessor(t_apontador A , t_chave chave);
void pre_ordem(t_apontador arvore);
void em_ordem(t_apontador arvore);
void pos_ordem(t_apontador arvore);
t_chave maximo(t_apontador A);
t_chave minimo(t_apontador A);
void libera_arvore(t_rbtree* arvore);

#endif