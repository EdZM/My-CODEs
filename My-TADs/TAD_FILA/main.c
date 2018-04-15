#include <stdio.h>
#include <stdlib.h>

#include "tad_fila.h"


int main(int argc, char const *argv[]){
	
	FILA* fil = criar_fila();

	enfileirar(fil, 34);
	enfileirar(fil, 33);
	enfileirar(fil, 234);
	enfileirar(fil, 103);
	enfileirar(fil, 325);

	NODE* aux = fil->inicio;


	while (aux != NULL){ //impressao antes da retirada de elementos

		printf("%d ", aux->elemento);

		aux = aux->proximo;

	}
	printf("\n");



	desenfileirar(fil);
	desenfileirar(fil);
	desenfileirar(fil);


	aux = fil->inicio;


	while (aux != NULL){ //impressao antes da retirada de elementos

		printf("%d ", aux->elemento);

		aux = aux->proximo;

	}
	printf("\n");

	free_fila(&fil);


return 0;
}