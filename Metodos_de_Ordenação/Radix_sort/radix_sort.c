#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

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


void radix_sort(int* a, int n){ //k é o número de tipos envolvidos
	
	int i;
    int *aux;
    int max = a[0];
    int exp = 1;

    aux = (int *)calloc(n, sizeof(int));

    for (i = 0; i < n; i++) { //encontrar o maior elemento da lista é necessário para saber quantos algarismos ele tem
        if (a[i] > max)
    	    max = a[i];
    }

    while (max/exp > 0) { // a cada while analiso um pedaço do numero (começando pelas unidades, dezenas, centenas...)
        int types[10] = { 0 };
    	for (i = 0; i < n; i++)
    	    types[(a[i] / exp) % 10]++; // Store count of occurrences in types[]
    	
    	for (i = 1; i < 10; i++)
    	    types[i] += types[i - 1];  // Change types[i] so that types[i] now contains actual position of this digit in a[]
    	
    	for (i = n - 1; i >= 0; i--)
    	    aux[--types[(a[i] / exp) % 10]] = a[i]; // Build the output array (a[])
    	
    	for (i = 0; i < n; i++)
    	    a[i] = aux[i]; // Copy the aux array to a[], so that a[] now contains sorted numbers according to current digit
    	
    	exp *= 10;
    }
  
free(aux);	
}



int main(int argc, char const *argv[]){
	
	if(argc == 2){
		int* a = NULL;
		int n = atoi(argv[1]);
		
		a = (int*)malloc(sizeof(int)*n);
		
		init(a, n , 0, 5*n);

		radix_sort(a, n);
		print_vec(a,n);
	
		free(a);
	}else{
		printf("Insira: ./<nome_Programa> <numero_de_elementos>\n");

	}

return 0;
}

