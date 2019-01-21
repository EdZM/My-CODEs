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



#include <stdio.h>
#include <stdlib.h>
#include "rbtree.h"

#define PRETO 2
#define VERMELHO 1

/*Função para somente inicializar a arvore que será usada em todo o trabalho
	parametro: 
		t_rbtree* arvore: endereço do t_apontador que aponta para a raiz da arvore vermelho e preto
*/
void inicializar_arvore(t_rbtree* arvore){
	*arvore = NULL;
}


/*Função para criar um nó para arvore
	parametros:
	 	t_rbtree* arvore: endereço do t_apontador que aponta para a raiz da arvore vermelho e preto
	 	t_chave item: item/valor/chave a ser inserido no nó que for criado
*/
void criar_raiz(t_rbtree* arvore, t_chave item){ 
	
	*arvore = (t_apontador) malloc (sizeof(no_rb));
	(*arvore)->esquerda = NULL;
	(*arvore)->direita = NULL;
	(*arvore)->pai = NULL;
	(*arvore)->chave = item;
	
}


/*Função para rotacionar para a direita um nó fornecido por parametro(apontado por p)
	parametros:
		t_apontador p: aponta para o nó que será rotacionado
		t_rbtree* arvore: endereço do t_apontador que aponta para a raiz da arvore vermelho e preto
						  (necessario esse endereço, pois pode ocorrer de a rotação alterar a raiz da arvore)	

*/
void rotacao_direita(t_apontador p, t_rbtree* arvore){
		
	t_apontador p2;

	p2 = (p)->esquerda;
	(p)->esquerda = (p2)->direita;
	
	if( (p2)->direita != NULL)
		(p2)->direita->pai = p;

	(p2)->pai = (p)->pai;

	if((p)->pai != NULL){
		if((p)->pai->esquerda == p) (p)->pai->esquerda = p2;
		else (p)->pai->direita = p2;
	
	} else {	
		*arvore = p2; //aqui a raiz é alterada
	
	}

	(p2)->direita = p;
	(p)->pai = p2;
	
}


/*Função para rotacionar para a esquerda um nó fornecido por parametro(apontado por p)
	parametros:
		t_apontador p: aponta para o nó que será rotacionado
		t_rbtree* arvore: endereço do t_apontador que aponta para a raiz da arvore vermelho e preto
						  (necessario esse endereço, pois pode ocorrer de a rotação alterar a raiz da arvore)	

*/
void rotacao_esquerda(t_apontador p, t_rbtree* arvore){

	t_apontador p2;

	p2 = (p)->direita;
	(p)->direita = (p2)->esquerda;

	if((p2)->esquerda != NULL){
		(p2)->esquerda->pai = p;
	}

	(p2)->pai = (p)->pai;
	
	if( (p)->pai != NULL ){
		
		if((p)->pai->direita == p) (p)->pai->direita = p2;
		else (p)->pai->esquerda = p2;
	
	} else {
		*arvore = p2; // aqui a raiz é alterada
	}
	(p2)->esquerda = p;
	(p)->pai = p2;
	
}


/*Função para inserir chaves distintas na arvore vermelho e preto.Essa função, alem de inserir um nó, 
	ela tambem recolore e/ou rotaciona os nós caso isso seja necessário, para manter a arvore balanceada.
	parametros:
		t_rbtree* arvore: endereço do t_apontador que aponta para a raiz da arvore (necessario pois pode ser necessario alterar a propria raiz )
		t_chave chave: chave que deseja-se inserir na arvore

*/
void inserir(t_rbtree* arvore, t_chave chave){ 
	
	t_apontador p, p2, paux; //p2 servirá para linkar o nó apontado por p, a seu nó pai
							 // aux servirá para quando for criar, de fato,	o novo nó 
	p = *arvore;
	p2 = NULL;

	//antes de inserir o nó deve-se, primeiro, chegar até a posição mais adequada para sua chave na arvore
	while (p != NULL){
		if(chave < (p)->chave){
  
			p2 = p; //p2 passa a apontar para o que será o pai de p
			if(p->esquerda != NULL)
				p = (p)->esquerda;
			else break;

		}else if(chave > (p)->chave){

			p2 = p;
			if(p->direita != NULL)
				p = (p)->direita;
			else break;

		}else {
			printf("erro\n");	//mensagem de erro para o caso de nao ser possivel adicionar uma chave, ou quando tentar adicionar chaves iguais
			exit(EXIT_FAILURE);
		}
					
	}

	criar_raiz(&paux, chave);

	if( p!= NULL &&  p->chave > chave ) p->esquerda = paux;
	else if(p != NULL) p->direita = paux;
	
	p2 = p;
	p = paux;
	

	if(p2 != NULL)
		(p)->pai = p2; // com isso o link entre p e o pai de p está feito


	(p)->cor = VERMELHO; // logo depois de inserido, um nó sempre tem a cor VERMELHA
		
	t_apontador tio = NULL;// apontadores para o tio de p e o avo de p,respectivamente
	t_apontador avo = NULL;

	while(p != NULL && (p)->pai != NULL){
		
		tio = NULL;
		avo = NULL;

		if((p)->cor == VERMELHO && (p)->cor == (p)->pai->cor ){ //Se tiver dois nós vermelhos consecutivos,
																// será necessário refazer a coloração de alguns nós e/ou rotações
																// baseando-se em 3 CASOS distintos
			avo = ((p)->pai->pai);

			if((avo)->esquerda != NULL && (avo)->direita == (p)->pai ){	// se o filho esquerdo do avo de p existir e o pai de p for 
				tio = (avo)->esquerda; 									// o filho direito do avo, o tio de p será o filho esquerdo do avo
				
			}else if((avo)->direita != NULL && (avo)->esquerda == (p)->pai){ // se o filho direito do avo de p existir e o pai de p for 
				tio = (avo)->direita;										 // o filho esquerdo do avo, o tio de p será o filho direito do avo
					
			}
			
			//CASO 1: nó tio de p existe e  é vermelho. Nesse caso não é necessário rotacionar nenhum nó, mas é necessario a recoloração 
			
			if ( tio != NULL && (tio)->cor == VERMELHO ) {
				//Recolorações do tio , do pai e do avo de p
				(tio)->cor = PRETO;
				(p)->pai->cor = PRETO;
				(avo)->cor = VERMELHO;


			} else{ //CASOS 2 e 3: só entro aqui se o tio for preto ou se ele nao existir. Aqui são feitas algumas rotações de fato

				if( (p)->pai == (avo)->esquerda ){ 
					if( p == (p)->pai->direita ) { 		//CASO 2.1: se p é filho direito de seu pai
						p = (p)->pai; 			   		//Rotacionar o nó pai de p uma vez para a esquerda.Depois disso é que se pode 	
						rotacao_esquerda((p), arvore);	//fazer a rotação do avo de p para a direita (incluida no CASO 3.1)

					}
					
					//CASO 3.1: 
						//nó pai é recolorido de PRETO
						//nó avo é recolorido de VERMELHO
					(p)->pai->cor = PRETO;
					(avo)->cor = VERMELHO;
					rotacao_direita((p)->pai->pai, arvore);
					
				} else { 
					if( p == (p)->pai->esquerda ) { 	// CASO 2.2: Inverso do CASO 2.1: se p é filho esquerdo de seu pai
						p = (p)->pai; 					//Rotacinar o nó pai de p uma vez para a direita.Depois disso é que se pode
						rotacao_direita((p), arvore);	// fazer a rotação do avo de p para esquerda(incluida no CASO 3.2)
						
					}
					 
					//CASO 3.2: 
						//nó pai é recolorido de PRETO
						//nó avo é recolorido de VERMELHO
					(p)->pai->cor = PRETO;
					(avo)->cor = VERMELHO;
					rotacao_esquerda((p)->pai->pai, arvore);
				}	
			}
		}	
		// p entao passa a apontar para o seu avo. Necessario para que se possa andar pela arvore
		p = ((p)->pai->pai);

	}

	if (*arvore == NULL ) *arvore = p;//quando inserir o primeiro nó , é preciso garantir que essa atribuição seja feita
	
	// Necessario recolorir a raiz de preto. Isso porque ao longo da inserção o nó raiz pode ser pintado de VERMELHO
	(*arvore)->cor = PRETO; 

}


/*Função para encontrar a chave de maior valor na arvore.
	parametro:
		t_apontador A: 	apontador que pode apontar para qualquer nó da arvore.Nesse trabalho o unico apontador
					   	que interessa nessa função e na de minimo é o que aponta para a raiz da arvore

*/
t_chave maximo(t_apontador A){

	t_apontador p;

	p = A;

	//O maximo é encontrado descendo por todos os nós da direita da arvore até não haver mais nós a direita.
	//Nesse momento encontrei o maximo.
	while (p->direita != NULL) p = p->direita; 

	return p->chave;


}


/*Função para encontrar a chave de menor valor na arvore.
	parametro:
		t_apontador A: 	apontador raiz da arvore

*/
t_chave minimo(t_apontador A){

	t_apontador p;

	p = A;

	//O minimo é encontrado descendo por todos os nós da esquerda da arvore até não haver mais nós a esquerda.
	//Nesse momento encontrei o minimo.
	while (p->esquerda != NULL) p = p->esquerda;

	return p->chave;

}



/*Função para encontrar a chave anterior à chave fornecida por parametro, se essa chave existir
	parametros:
		t_apontador A: apontador para o nó, cujo predecessor será encontrado
		t_chave chave: chave escolhida	

*/
t_chave predecessor(t_apontador A , t_chave chave){

	t_apontador p, p2;
	p = A;
	int flag = 0;//Usada para quando nao encontrar a chave fornecida por parametro

	
	while ( p->chave != chave ){ //Usado para chegar a chave, cujo antecessor sera pesquisado
				
		if(chave < (p)->chave){	
			p = (p)->esquerda;
				
		}else if(chave > (p)->chave){
			p = (p)->direita;
			
		}
		if (p->esquerda == NULL && p->direita == NULL && p->chave != chave){// Se cheguei a uma folha e a chave ainda é diferente da
			flag = -1;														// que foi fornecida, é indicado que houve erro na busca.
			break;															// E entao o while é interrompido
		}
	}

	if(flag != -1){ //se um erro for detectado na busca anterior, o valor -1 é retornado, e uma mensagem de erro é impressa
		
		if (p->esquerda != NULL){ //se p tiver filho a esquerda, desço uma vez para a esquerda de p e depois tudo para a direita
								  // Feito isso, a chave do nó encontrado é a predecessora
			p = p->esquerda;
			while(p->direita != NULL){
				p = p->direita;
						
			}
			return p->chave;

		} else { // no caso de p nao ter filho a esquerda, sobe-se na arvore(de pai em pai) até encontrar um nó que seja 
				 // filho direito de p2 (aponta para o pai de p ) 
			p2 = p->pai;

			while(p2->direita != p && p2->pai != NULL){
				p = p->pai;
				p2 = p->pai;

			}
		
			if(p2->pai == NULL){ 
				if( p2->esquerda == p){
					return -1;// o nó não tem predecessor
				}
				else 
					return p2->chave;	
			} else
				return p2->chave;
				
		}
	
	}else
		return flag;

}

	
/*Função para encontrar, analogamente à função predecessor(), a chave sucessora à chave fornecida por parametro, se essa chave existir
	parametros:
		t_apontador A: apontador para o nó, cujo sucessor será encontrado
		t_chave chave: chave escolhida	

*/
t_chave sucessor(t_apontador A , t_chave chave){

	t_apontador p, p2;
	p = A;
	int flag = 0;
	
	
	while ( p->chave != chave ){ //Usado para chegar a chave, cujo sucessor sera pesquisado
				
		if(chave < (p)->chave){	
			p = (p)->esquerda;
		
		}else if(chave > (p)->chave){
			p = (p)->direita;
		
		}
		if (p->esquerda == NULL && p->direita == NULL && p->chave != chave){
			flag = -1;
			break;
		}
	}

	if(flag != -1){ //Caso a chave tenha sido encontrada sem problemas...

		if (p->direita != NULL){// Se p tiver um filho direito, desço na arvore uma vez para a direita e depois tudo para a esquerda
								// Feito isso, o nó a que cheguei terá chave, sucessora àquela que foi passada por parametro
			p = p->direita;		// Isso é feito de forma oposta à função predecessor()
			while(p->esquerda != NULL){
				p = p->esquerda;
						
			}
			return p->chave;

		} else { // No caso de p ter filho a esquerda, subo na arvore(de pai em pai) até atingir um nó que seja
				 // filho esquerdo de p2 (aponta para o pai de p ) 	
			p2 = p->pai;

			while(p2->esquerda != p && p2->pai != NULL){
				p = p->pai;
				p2 = p->pai;

			}
		
			if(p2->pai == NULL){
				if( p2->direita == p){
					return -1; //indica que o nó fornecido nao tem sucessor
				}
				else 
					return p2->chave;	
			} else
				return p2->chave;
			
		}
	
	}else
		return flag;
}

/*Funções para a impressao: Pre_ordem --> imprime a chave primeiro e anda para a esquerda e, depois, para a esquerda recursivamente 
							
							Em_ordem --> imprime as chaves em ordem crescente
							
							Pos_ordem --> percorre recursivamente a arvore, primeiro a esquerda, depois a direita e, por fim imprime as chaves


	Parametros(das 3 funções):
		t_apontador arvore: apontará para a raiz da arvore em todas as vezes em que essas funções forem usadas
	

*/
void pre_ordem(t_apontador arvore){
	if(arvore != NULL){
		printf("%d ",arvore->chave);
		pre_ordem(arvore->esquerda);
		pre_ordem(arvore->direita);
	}
	
}

void em_ordem(t_apontador arvore){
	if(arvore != NULL){
		em_ordem(arvore->esquerda);
		printf("%d ",arvore->chave);
		em_ordem(arvore->direita);
	}
	
}

void pos_ordem(t_apontador arvore){
	if(arvore != NULL){
		pos_ordem(arvore->esquerda);
		pos_ordem(arvore->direita);
		printf("%d ",arvore->chave);
	}
	
}

/*Função que desaloca a arvore vermelho e preto, seguindo o mesmo criterio usado na impressao em Pos_ordem
	parametro:
		t_rbtree* arvore: endereço do apontador que aponta para a raiz da arvore, que será desalocada
*/
void libera_arvore(t_rbtree* arvore){
	if(*arvore != NULL){
		libera_arvore(&(*arvore)->esquerda);
		libera_arvore(&(*arvore)->direita);
		free(*arvore);
	}
}










