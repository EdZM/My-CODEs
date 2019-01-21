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


/* Insertion sort: A ideia principal aqui é que, dado certo elemento x do vetor , eu vá deslocando todos os menores que x até encontrar sua posição ideal
	Ex: Para facilitar lembre do exemplo de aula:
		-Nele, tinha uma fila horizontal de pessoas, cada uma delas com uma carta do baralho.
		
		-Havia alguem que percorria ordenadamente essa fila apontando para cada uma das pessoas(a pessoa dava um passo a frente),
		 perguntando se o valor que ela tinha era menor que as pessoas a sua esquerda. SE fosse menor, aquele pedaço da fila ia sofrendo deslocamentos até que o valor da pessoa atual 
		 fosse maior do que a pessoa comparada. 
		
		-Quando o valor de sua carta era maior do que a pessoa comparada, a pessoa que deu um passo a frente ocupava a posição seguinte a da pessoa comparada naquele momento

		
Caracteristicas do insertion sort:

****Vantagens:
-> É um dos 3 algoritmos Intuitivos: a implementação é relativamente mais fácil
-> Estável == posições que tem mesmo valor não são trocadas de lugar em nenhum momento 
-> Inline == Não há necessidade de espaço extra 
-> Online == O algoritmo se comporta bem na inserção de novos elementos
-> Faz várias trocas e poucas comparações

****Desvantagens:
-> A movimentação dos elementos no vetor é altamente custosa ao longo da ordenação
-> - eficiente que merge e quick sort ( O(nlogn()) )


-> Complexidade :
	melhor caso: O(n) --> o vetor já está ordenado
	caso médio: O(n^2 / 4) --> o vetor esta com valores em qualquer ordem, bagunçados  (condição mais usual)
	pior caso: O(n^2) --> o vetor está INVERSAMENTE ordenado


->(observação): Costuma ser melhor que o bubble sort quando o vetor está quase ordenado(O bubble faria comparações desnecessárias, o que levaria a um maior custo de tempo)
->(observação): Costuma ser pior quando o vetor está INVERSAMENTE ordenado(O bubble não se sairia muito melhor na mesma situação). 
->(observação): A complexidade do bubble sort é igual a do insertion 
********Código feito em aula:

void insert(int a[], int n) {
	int i;
	for(i = 1; i < n; i++) {
		int tmp = a[i];
		int k = i - 1;
		
		while(k >= 0 && tmp < a[k]) {
			a[k + 1] = a[k];
			k--;
		}
	
	a[k + 1] = tmp;
	}
}

VERSAO RECURSIVA( ARRUMAR ==> ESTOU FAZENDO TROCAS DEMAIS )
void insertion_sort_rec(int* vec, int size, int i, int j){

	int tmp;
		
	if( i == 0 || i == size){
		return ;
	
	}else if (vec[i] < vec[i-1]){
		
		tmp = vec[i-1];
		vec[i-1] = vec[i];
		vec[i] = tmp;

		insertion_sort_rec(vec, size, i-1, j);

	}

	if (i == j){
		insertion_sort_rec(vec, size, i+1, j+1);
	}

}

*/
void insertion_sort(int* a, int n){

	int tmp;

	for (int i = 1; i < n; i++){
		tmp = a[i];
		atrib_counter++;

		int k = i - 1;
		
		while( ++comp_counter && (k >= 0 && tmp < a[k]) ) { 
			a[k + 1] = a[k];
			atrib_counter++;
			k--;
			if(k < 0)comp_counter--; //evita que a contagem de comparações seja incrementada quando a condição k>=0 for falsa
		}
		a[k+1] = tmp;
		atrib_counter++;
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


	insertion_sort(a, n);
	print_vec(a,  n);
	printf("Comparações feitas: %ld\n", comp_counter);
	printf("Atribuições feitas: %ld\n", atrib_counter);

free(a);
return 0;
}