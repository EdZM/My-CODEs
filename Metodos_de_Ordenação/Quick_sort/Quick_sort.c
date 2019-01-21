#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PIVOT(i,j) (i+j)/2


/* Quick sort: A ideia principal aqui é 
	Ex: 
		
Caracteristicas do Quick sort:

****Vantagens:
	-> Evita trocas desnecessarias




-> Usa um pivô que vai mudando frequentemente . A escolha dele influencia diretamente na complexidade
-> separa o vetor em duas partições, que se separam em quatro, depois em oito, e assim por diante
-> Usa indicadores de fim e inicio dos vetores ou partições
 

-> Complexidade :
	Tempo:
		melhor caso: O(nlogn) --> gera partições de mesmo tamanho ou tamanho balanceado 
		pior caso: O(n^2) --> quando a escolha do pivo(ex: se ele for o maior ou o menor do vetor) 
				   			  gera uma partição de tamanho 1 e outra de tamanho n-1
	Espaço:
		melhor caso: O(logn) --> gera partições de mesmo tamanho
		pior caso: O(n) --> quando a escolha do pivo(ex: se ele for o maior ou o menor do vetor) 
				   gera uma partição de tamanho 1 e outra de tamanho n-1

->(observação): 
->(observação): 
->(observação): 


Implementação feita em aula :



*/




void print_vec(int vec[], int n){

	for (int i = 0; i < n; i++)	{
		printf("%d ", vec[i]);
	}	
	printf("\n");

}

void swap_(int* a, int pos0, int pos1 ){
	int tmp = a[pos0];
	a[pos0] = a[pos1];
	a[pos1] = tmp;
}

int pivot_choose(int* a, int left, int right){ //metodo da mediana de tres para escolher o pivo

	int mid = (left + right)/2;
	if (a[left] < a[right])	{
		swap_(a, left, right);
	}
	if (a[left] < a[mid])	{
		swap_(a, left, mid);
	}
	if (a[mid] < a[right])	{
		swap_(a, mid, right);
	}

	return mid;
}

int quick_sort(int* a, int inicio, int fim){
	
	/*Opções legais pra escolha do pivo
		opção 1:(randomizada)
			srand(time(NULL));
			int r = (inicio + rand()%(fim-inicio+1)); //funciona tambem
		opção 2:(elemento central)
			pivo = a[(i+j)/2];
	*/

	int i = inicio;
	int j = fim;
	int pivo;

	pivo = a[ pivot_choose(a, inicio, fim) ]; // escolha do pivo baseada em mediana de dois
	


	while(j >= i){
		while(a[i] < pivo) i++;
		while(a[j] > pivo) j--;

		if(i <= j){ 
			swap_(a, i, j);
			i++;
			j--;
		}

	}

	if(inicio < j) quick_sort(a, inicio, j);
	if(i < fim) quick_sort(a, i, fim);
}




int main(int argc, char const *argv[]){
	
	int* vec = NULL;
	int n = 100;

	//printf("Tamanho do vetor: ");
	//scanf("%d", &n);
	srand(time(NULL));
	vec = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++){
		vec[i] = rand()%1000;
	}
	//print_vec(vec,n);
	quick_sort(vec, 0, n-1);
	print_vec(vec,n);
	


return 0;
}
