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
void selection_sort(int* a, int n){

	int min_pos;

	for (int i = 0; i < n-1; i++){

		min_pos = i ; //posição do menor valor

		for (int j = i+1; j < n ; j++){
			if( ++comp_counter && (a[j] < a[min_pos])){
				min_pos = j; // guardando a posição em que encontrei um valor menor que o atual 
			}
		}
		swap_(a, i , min_pos); //a troca se só depois de ter encontrado a posição correta
		atrib_counter+=3;
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
	
	selection_sort(a, n);
	print_vec(a,  n);
	printf("Comparações feitas: %ld\n", comp_counter);
	printf("Atribuições feitas: %ld\n", atrib_counter);

free(a);
return 0;
}