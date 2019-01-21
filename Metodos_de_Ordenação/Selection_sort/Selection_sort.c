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


/* Selection sort: A ideia principal aqui é que, 
	Ex: Para facilitar lembre do exemplo de aula:
		-Nele, tinha uma fila horizontal de pessoas, cada uma delas com uma carta do baralho(vec[]).

		-Havia alguem que percorria ordenadamente essa fila apontando para cada uma das pessoas(i) e uma outra pessoa marcando a posição do menor valor(m),

		-(i) marcava a posição que ia ser comparada com cada uma depois dele. Quando fosse encontrado o menor, sua posição era marcada pela pessoa(m) e, então,
		comparada com a pessoa (i).

		- Se a pessoa(m) fosse menor que a (i), ela entao trocava de lugar com a ultima

		Detalhe: Cada vez que a pessoa(i) andava o caminho de (m) ficava mais limitado, curto
		

		
Caracteristicas do Selection sort:

****Vantagens:

-> É um dos 3 algorimos intuitivos ("facil" implementação)
-> In-line(in-place): Espaço extra não é necessário(as operações são feitas em cima do mesmo vetor). Isso faz com que use menos memoria
-> É um dos mais rapidos para vetores pequenos


****Desvantagens:
-> Não é On-line: não se comporta bem se forem adicionados novos elementos no vetor já ordenado
-> É um dos mais lentos para vetores grandes
-> Instável : posições que tem mesmo valor podem ser trocadas entre si durante a ordenação
-> Sempre tem complexidade O(n^2)

-> + comparações do que o insertion(não fujo de ter que percorrer todo o resto do vetor a cada iteração do selection. No insertion eu nao preciso necessarimente percorrer o resto do vetor),
	 porém é comparável ao bubble.


-> Complexidade :
	melhor caso: O(n^2) --> 
	caso médio: O(n^2) --> 
	pior caso: O(n^2) --> 


->(observação): 
->(observação): 
->(observação): 

********Código feito em aula:
void selection(int a[], int n) {
	int i;
	for(i = 0; i < n - 1; i++) {
		int m = i; 	//min_pos na minha versão
		int k; 		//j na minha versao

		for(k = i + 1; k < n; k++) {
			if(a[k] < a[m]) {
			m = k;
			}
		}

	int tmp = a[i];
	a[i] = a[m];
	a[m] = tmp;

	}
}


*/
void selection_sort(int* vec, int n){

	int min_pos;
	int tmp;

	for (int i = 0; i < n-1; i++){

		min_pos = i ; //posição do menor valor (NAO é o menor valor propriamente dito, pq isso é desnecessario). Isso facilita na hora de trocar

		for (int j = i+1; j < n ; j++){
			if(vec[j] < vec[min_pos]){
				min_pos = j; //estou guardando a posição em que encontrei um valor menor que o atual 
			}
		}
		tmp = vec[i];
		vec[i] = vec[min_pos];
		vec[min_pos] = tmp;

	}

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

	selection_sort(vec1, n);
	selection_sort(vec2, n);
	
	print_vec(vec1, n);
	print_vec(vec2, n);

free(vec1);
return 0;
}