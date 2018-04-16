#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tad_arvore_abb.h"



int main(int argc, char* argv[]){

	ARVORE* abb = NULL;
	int random_key;


	abb = criar_arvore();

	srand(time(NULL));



	//for (int i = 0; i < 15; ++i)	{
		
	//	random_key = rand()%(50); // sorteira uma chave entre 0 e 49
	
	//	printf("Chave a ser inserida: %d\n", random_key);
	//	inserir(&abb, random_key);
	
	//}

	inserir(&abb, 10);
	inserir(&abb, 9);
	inserir(&abb, 8);
	inserir(&abb, 7);
	inserir(&abb, 17);
	inserir(&abb, 12);
	inserir(&abb, 11);
	inserir(&abb, 13);
	inserir(&abb, 20);
	inserir(&abb, 14);





	if( busca(abb, 8) == 1 ) { // não há como saber exatamente se vou encontrar a chave 36 , pois a inserção é de chaves ALEATORIAS entre 0 e 49
		printf("Chave encontrada\n");
	
		//remover(&abb, 8); // nó com um unico filho
		//remover(&abb, 14); // nó com dois filhos

		printf("%p\n", abb->raiz->esquerda->esquerda->esquerda);
		
		remover(&abb, 8);	// nó com dois filhos

		printf("%p\n", abb->raiz->esquerda->esquerda->esquerda);


	} else {
		printf("Chave não encontrada\n");
	}

	
	printf("\n\nImpressao em ordem dos elementos da arvore: \n");

	impressao_em_ordem(abb->raiz); // essa função imprime a arvore toda ou qualque sub_arvore, basta informar de qual nó eu desejo partir

return 0;	
}