#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tad_arvore_abb.h"



int main(int argc, char* argv[]){

	ARVORE* abb = NULL;
	int random_key;


	abb = criar_arvore();

	srand(time(NULL));

	inserir(&abb, 1);
	inserir(&abb, 1);


	for (int i = 0; i < 10; ++i)	{
		random_key = rand()%(50); // sorteira uma chave entre 0 e 49
		printf("Chave a ser inserida: %d\n", random_key);
		inserir(&abb, random_key);
	}
	
	printf("\n\nImpressao em ordem dos elementos da arvore: \n");

	impressao_em_ordem(abb->raiz); // essa função imprime a arvore toda ou qualque sub_arvore, basta informar de qual nó eu desejo partir

return 0;	
}