#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void print_vec(int* a, int n){

	for (int i = 0; i < n; i++){
		printf("%d ",a[i] );
	}
	printf("\n");

}

void random_vec_generator(int* a, int n, int range){

	srand(time(NULL));
	for (int i = 0; i < n; i++){
		a[i] = rand()%(range+1); // gera aleatoriamente valores entre 1 e range
	}


}

void shell_sort(int* a, int n){

	int gaps[8] = {701,501,132,57,23,10,4,1}; //lista fixa dos gaps que garantem a melhor execução ao algoritmo. 

	for (int i = 0; i < 8; i++){
		int g = gaps[i];
		for (int j = g; j < n; j++)	{
			int tmp = a[j];
			int k = j - g;
			while( k >= 0 && tmp < a[k] ){
				a[k+g] = a[k];
				k -= g;
			}
			a[k+g] = tmp;
		}

	}

}


int main(int argc, char const *argv[]){

	int*a = NULL;
	if(argc == 3){	
		int n = atoi(argv[1]);
		int p = atoi(argv[2]);
		a = (int*)malloc(sizeof(int)*n);

		random_vec_generator(a, n, p);

		shell_sort(a, n);

		print_vec(a,n);

	}else{
		printf("Insira: ./<nome do programa> <numero de elementos do vetor> <intervalo de numeros> \n");

	}
	

	return 0;
}