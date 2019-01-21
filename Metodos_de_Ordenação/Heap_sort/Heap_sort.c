#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

long int comp_counter = 0; //contador de comparações entre elementos do vetor 
long int atrib_counter = 0;//contador de atribuições/trocas envolvendo elementos do vetor

void init(int a[], int n, int step, int range){
	
	srand(time(NULL));

	for (int i = 0; i < n; i++)	{
		int base = i * step;
		int offset = rand() % range;
		a[i] = base + offset;
	}
}

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


int main(int argc, char* argv[]){

	int n;  //numero de elementos
	//int k;	// indice para o 10^k --> deve variar entre 2 e 7
	int* a = NULL;

	//printf("Digite o valor de k: ");
	//scanf("%d", &n); 
	

	n = atoi(argv[1]);
	//n = pow(10,k);
	
	a = (int*)malloc(sizeof(int) * n);
	

	init(a, n , 0, 5*n); 	//vetor aleatorio
	//init(a, n, 10, 100); 	//vetor quase ordenado
	//init(a, n, -1, 100); 	//vetor quase inversamente ordenado
	//init(a, n, 0, n/10);	//vetor com muitos valores repetidos

	comp_counter = 0;
	atrib_counter = 0;

	heapsort(a, n);
	
	printf("%ld\n", comp_counter);
	printf("%ld\n", atrib_counter);


return 0;	
}