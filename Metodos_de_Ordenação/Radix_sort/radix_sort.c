#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

long int comp_counter = 0; //variavel global para contar as comparações entre elementos do vetor 
long int atrib_counter = 0;//variavel global para contar as atribuições/trocas envolvendo elementos do vetor


//função para a criação dos 4 cenarios a que os metodos de ordenação serão submetidos
void init(int* a, int n, int step, int range){
	
	srand(time(NULL));

	for (int i = 0; i < n; i++)	{
		int base = i * step;
		int offset = rand() % range;
		a[i] = base + offset;
	}
}


//função para a impressão do vetor 
void print_vec(int* a, int n){

	for (int i = 0; i < n; i++){
		printf("%d ",a[i] );
	}
	printf("\n");

}


void radix_sort(int* a, int n){ //k é o número de tipos envolvidos
	
	int i;
    int *aux;
    int max = a[0];
    int exp = 1;

    atrib_counter++;

    aux = (int *)calloc(n, sizeof(int));

    for (i = 0; i < n; i++) { //encontrar o maior elemento da lista é necessário para saber quantos algarismos ele tem
        if (++comp_counter && a[i] > max)
    	    max = a[i];
   			atrib_counter++;
    }

    while (max/exp > 0) { // a cada while analiso um pedaço do numero (começando pelas unidades, dezenas, centenas...)
        int types[10] = { 0 };
    	atrib_counter++;
    	
    	for (i = 0; i < n; i++)
    	    types[(a[i] / exp) % 10]++; // Armazena a contagem de ocorrencias em types[]
    	
    	for (i = 1; i < 10; i++)
    	    types[i] += types[i - 1];  // Altera types[i] para que ele agora contenha a posição atual desse digito em a[]                    
    		atrib_counter++;

    	for (i = n - 1; i >= 0; i--)
    	    aux[--types[(a[i] / exp) % 10]] = a[i]; // Monta o vetor de saida (a[])
    		atrib_counter++;

    	for (i = 0; i < n; i++)
    	    a[i] = aux[i]; // Copia o vetor auxiliar para a[], para que a[] contenha agora os numeros ordenados de acordo com o digito atual
    		atrib_counter++;

    	exp *= 10;
    }
  
free(aux);	
}



int main(int argc, char const *argv[]){
	
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

	radix_sort(a, n);

	print_vec(a,  n);
	printf("Comparações feitas: %ld\n", comp_counter);
	printf("Atribuições feitas: %ld\n", atrib_counter);

	

free(a);
return 0;
}

