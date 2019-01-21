#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void print_vec(int vec[], int n){

	for (int i = 0; i < n; i++)	{
		printf("%d ", vec[i]);
	}	
	printf("\n");

}


/* Bubble sort: A ideia principal aqui é percorrer o vetor diversas vezes, e a cada passagem fazer flutuar(por isso BUBBLE) para o topo o maior elemento da sequência
	Ex: Para facilitar lembre do exemplo de aula:
		-Nele, tinha uma fila horizontal de pessoas, cada uma delas com uma carta do baralho(vec[]).

		-Havia alguem que percorria ordenadamente essa fila apontando para cada uma das pessoas(j) e ia até outra pessoa (i) que apontava para a ultima posição ordenada(i decrementava)

		-A pessoa(j) se comparava com a pessoa(j+1). Se a primeira tivesse um valor maior, ela entao trocava de lugar com a ultima. Isso até chegar a pessoa(i) 
		 A cada iteração o numero de pessoas a serem verificadas diminuia, pois para cada vez que j percorria a fila, o maior valor FLUTUAVA para sua devida posição

		
Caracteristicas do Bubble sort:

****Vantagens:

-> É um dos 3 algorimos intuitivos ("facil" implementação)
-> Estável(em posições que contenham mesmo valor no vetor nao há troca da ordem em que esses elementos repetidos aparecem)
-> In-line : significa que o bubble não precisa de memoria extra, já que realiza todas as suas operações em cima de um mesmo vetor


****Desvantagens:
-> 
-> 
-> 
-> 

-> 


-> Complexidade :
	melhor caso: O(n) --> n operações RELEVANTES(ex: trocar dois numeros de lugar), sendo n o numero de elementos do vetor
	caso médio: O(n^2) --> 
	pior caso: O(n^2) --> 


->(observação): não é recomendado para programas que precisem de velocidade e operem com quantidade elevada de dados
->(observação): 
->(observação): 

********Código feito em aula:

void bubble(int a[], int n) {
	int i;
	int k;
	for(i = n - 1; i > 0; i--) {
		for(k = 0; k < i; k++) {
			if(a[k] > a[k+1]) {
				int t = a[k];
				a[k] = a[k+1];
				a[k+1] = t;
			}
		}
	}
}

void bubble_sent(int a[], int n) {

	int i = n - 1;	
	while(i > 0) {
		int s = -1;
		int k;
		
		for(k = 0; k < i; k++) {
			if(a[k] > a[k+1]) {
			s = k;  			//marca onde houve a ultima troca
			int t = a[k];
			a[k] = a[k+1];
			a[k+1] = t;
			}
		}
		i = s;
	}
}


*/
void bubble_sort(int* vec, int n){
	
	for (int i = n-1; i >= 0 ; i--)	{
		for (int k = 0; k < i; k++)	{
			if(vec[k] > vec[k+1]){
				int tmp = vec[k];
				vec[k] = vec[k+1];
				vec[k+1] = tmp;

			}
		}
	}
	
	/* OUTRO MODO (funciona tambem, mas tambem nao é muito recomendado, porque mesmo quando estiver tudo ordenado eu posso acabar percorrendo o vetor muitas vezes sem precisar)
	
	for (int i = 1; i < n ; i++)	{
		for (int k = 0; k < n-1; k++)	{
			if(vec[k] > vec[k+1]){
				int tmp = vec[k];
				vec[k] = vec[k+1];
				vec[k+1] = tmp;

			}
		}
	}

	*/
}

void bubble_sort_sentinel(int* vec, int n){
	
	for (int i = n-1 ; i > 0 ; ){
		int s =-1;
		for (int j = 0; j < i; j++){
			if(vec[j] > vec[j+1]){
				s = j; 					// salva onde houve a ultima troca. Limita um pouco o espaço percorrido por j até i (que a final do for terá o valor de s)
				int tmp = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = tmp;
			}
			
		}
		i = s;
	}

}

void bubble_sort_cocktail(int* vec, int n){

	

}


int main(int argc, char* argv[]){

	int* vec1 = NULL; // ponteiro usado para um vetor de numeros aleatorios entre 0 e 99
	int vec2[] = {34,1,2,17,5,1,31};
	int n = 7;
	
	vec1 = (int*)malloc(n*sizeof(int));
	srand(time(NULL));

	for (int i = 0; i < n; i++){
		vec1[i] = rand()%100;		
	}

	bubble_sort(vec1, n);
	bubble_sort_sentinel(vec2, n);
	
	print_vec(vec1, n);
	print_vec(vec2, n);

free(vec1);
return 0;
}