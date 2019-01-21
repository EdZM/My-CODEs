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

	printf("Vetor ordenado: ");
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


void heapfy(int *a, int start, int end){
	
	int parent, child;
	
	parent = start;
	
	while(parent < end){
		child = 2*parent + 1;
		if(child < end){
			
			if(++comp_counter && child + 1 < end && (a[child] < a[child + 1]) ){
				child++;
			}
			if(++comp_counter && a[child] > a[parent]){
				swap_(a, child, parent);
				atrib_counter+=3;
			}
		}
		parent = child;
	}
	

}

void heapsort(int *a, int n) {
	
	for (int i = n-1; i >= 0 ; i--){
		heapfy(a, i, n); //antes de iniciar a ordenação é necessário transformar o vetor de entrada em uma estrutura heap
	}

	for (int i = n-1; i > 0 ; i--){
		swap_(a,0,i);
		atrib_counter+=3;
		heapfy(a,0,i);

	}
	
}

int main(int argc, char* argv[]){

	int n;  //numero de elementos
	int* a = NULL; 

	n = atoi(argv[1]); //recebe como parametro o segundo argumento de entrada no momento da execucao para ser o tamanho do vetor
	
	a = (int*)malloc(sizeof(int) * n); // vetor que deve conter os números
	

	//4 opções para geração dos números do vetor
	init(a, n , 0, 5*n); 	//vetor aleatorio
	//init(a, n, 10, 100); 	//vetor quase ordenado
	//init(a, n, -1, 100); 	//vetor quase inversamente ordenado
	//init(a, n, 0, n/10);	//vetor com muitos valores repetidos

	comp_counter = 0;
	atrib_counter = 0;

	heapsort(a, n);
	
	print_vec(a,  n);
	printf("Comparações feitas: %ld\n", comp_counter);
	printf("Atribuições feitas: %ld\n", atrib_counter);

free(a);
return 0;	
}