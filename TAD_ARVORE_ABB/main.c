#include <stdio.h>
#include <stdlib.h>
#include "tad_arvore_abb.h"


int main(int argc, char* argv[]){

	ARVORE* abb = NULL;

	abb = criar_arvore();

	inserir(abb, 2);
	inserir(abb, 3);


	//printf("%d\n", abb->raiz->elemento);

return 0;	
}