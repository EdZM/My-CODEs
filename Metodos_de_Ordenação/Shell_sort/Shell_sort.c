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

void shell_sort(int* a, int n){

	int gaps[8] = {701,501,132,57,23,10,4,1}; //lista fixa dos gaps que garantem a melhor execução ao algoritmo. 

	for (int i = 0; i < 8; i++){
		int g = gaps[i];
		atrib_counter++;
		for (int j = g; j < n; j++)	{
			int tmp = a[j];
			atrib_counter++;

			int k = j - g;
			while( ++comp_counter && ( k >= 0 ) && ( tmp < a[k] ) ){
				a[k+g] = a[k];
				atrib_counter++;
				
				k -= g;
			}
			a[k+g] = tmp;
			atrib_counter++;
		}
	}

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

	shell_sort(a,n);

	print_vec(a,  n);
	printf("Comparações feitas: %ld\n", comp_counter);
	printf("Atribuições feitas: %ld\n", atrib_counter);

	

free(a);
	

	return 0;
}