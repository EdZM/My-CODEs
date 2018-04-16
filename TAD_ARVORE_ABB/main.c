#include <stdio.h>
#include <stdlib.h>
#include "tad_arvore_abb.h"


int main(int argc, char* argv[]){

	ARVORE* abb = NULL;

	abb = criar_arvore();

	inserir(&abb, 2);
	inserir(&abb, 3);
	inserir(&abb, 4);
	inserir(&abb, 1);
	inserir(&abb, 0);
	

	printf("chave esquerda: %d\n", abb->raiz->esquerda->esquerda->elemento );
	

return 0;	
}