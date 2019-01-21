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

//função para a trocar 2 duas posições especificas do vetor
void swap_(int* a, int pos0, int pos1 ){
	int tmp = a[pos0];
	a[pos0] = a[pos1];
	a[pos1] = tmp;
}

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
void quick_sort(int* a, int inicio, int fim){
	
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
	int piv_pos = ( (int)(i+j)/2 ); // escolha do pivo como sendo o elemento do meio do vetor analisado

	pivo = a[piv_pos];
	atrib_counter++;

	//particionamento
	while(i <= j){
		while(++comp_counter && (a[i] < pivo) && (i < fim) ) i++;
		while(++comp_counter && (a[j] > pivo) && (j > inicio) ) j--;

		if(i <= j){ 
			swap_(a, i, j);
			atrib_counter+=3;
			i++;
			j--;
		}

	}


	if(inicio < j) quick_sort(a, inicio, j);
	if(i < fim) quick_sort(a, i, fim);

}
//OBS.: em caso de problemas com a ordenação retire as contagens 



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

	quick_sort(a, 0, n-1);
	
	print_vec(a,  n);
	printf("Comparações feitas: %ld\n", comp_counter);
	printf("Atribuições feitas: %ld\n", atrib_counter);

	
free(a);
return 0;
}
