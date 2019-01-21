#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PAI(x) (x-1)/2
#define FILHO_ESQ(x) 2*x + 1
#define FILHO_DIR(x) 2*x + 2

/* HEAP sort: A ideia principal aqui é que, os numeros de um vetor qualquer sejam INSERIDOS numa HEAP MINIMA e depois RETIRADOS. Feito isso o vetor estará completamente ordenado
	Ex: 
		
Caracteristicas do HEAP sort:

****Vantagens:
-> Tem um desempenho em tempo de execução muito bom em conjuntos ordenados aleatoriamente
-> Tem um uso de memória bem comportado 
-> Seu desempenho em pior cenário é praticamente igual ao desempenho em cenário médio.
 

****Desvantagens:
-> NAO é Inline == Há necessidade de espaço extra 


-> Complexidade :
	melhor caso: O(nlogn) --> o vetor já está ordenado 
	caso médio: O(nlogn) --> o vetor esta com valores em qualquer ordem, bagunçados  (condição mais usual)
	pior caso: O(nlogn) --> o vetor está INVERSAMENTE ordenado


->(observação): -INstável ??????
->(observação): 
->(observação): 


Uma Forma + simples de implementar e que funciona (fonte: wiki ):

void heapsort(int a[], int n) {
   int i = n / 2, pai, filho, t;
   while(true) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n == 0) return;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}

*/


typedef struct {
	int h_capacity;
	int current_size;
	int *h_array;

}MIN_heap;


void swap(int* a, int* b ){
	int tmp = *a;
	*a = *b;
	*b = tmp;

}

MIN_heap* MIN_heap_init( int size ){
	MIN_heap* m_heap = NULL;
	
	m_heap = (MIN_heap*) malloc(sizeof(MIN_heap));
	m_heap->h_array = NULL;
	m_heap->h_capacity = size;
	m_heap->current_size = 0;
	m_heap->h_array = (int*)malloc(sizeof(int) * size );

return m_heap;

}

void MIN_heap_insert(MIN_heap* m_heap, int key){

	if ( m_heap->current_size <= m_heap->h_capacity ){
		
		m_heap->h_array[ m_heap->current_size ] = key;		
		int j = m_heap->current_size;
		
		while( j != 0 && m_heap->h_array[PAI(j)] > m_heap->h_array[j]){
			swap(  &m_heap->h_array[PAI(j)],  &m_heap->h_array[j]  );
			j = PAI(j);
		}			
		m_heap->current_size++;
	
	} else {	
		printf("HEAP is full!!\n");
	}
}

void heapify(MIN_heap* m_heap, int i){

	int dir = FILHO_DIR(i);
	int esq = FILHO_ESQ(i);
	int minimo = i; // minimo entre os dois filhos

	if(esq < m_heap->current_size && m_heap->h_array[esq] < m_heap->h_array[i] )minimo = esq;
	if(dir < m_heap->current_size && m_heap->h_array[dir] < m_heap->h_array[minimo] )minimo = dir;
	if(minimo != i){ // se a posição 'minimo' continuar a ser menor do que os filhos, não é preciso fazer mais o heapify

		swap( &m_heap->h_array[i], &m_heap->h_array[minimo]  );
		heapify(m_heap, minimo);
	
	}

}

int heap_extract_min(MIN_heap* m_heap){

	int root = m_heap->h_array[0];		
	
	if(m_heap->current_size == 1){
		m_heap->current_size--;	
	}	
	
	if(m_heap->current_size > 1) {
		m_heap->h_array[0] =  m_heap->h_array[ m_heap->current_size - 1 ];	
		m_heap->current_size--;
		heapify(m_heap, 0);
	}
	
return root;
}


void heap_sort(int* vec, int n){

	MIN_heap* m_heap = NULL; 
	m_heap = MIN_heap_init(n);	
	
	for (int i = 0; i < n; i++)	{
		MIN_heap_insert(m_heap, vec[i]);
	}

	int j = 0;
	while (m_heap->current_size > 0){		
		vec[j++] = heap_extract_min(m_heap);

	}	

}


void print_vec(int vec[], int n){

	for (int i = 0; i < n; i++)	{
		printf("%d ", vec[i]);
	}	
	printf("\n");

}

int main(int argc, char* argv[]){

	if(argc != 2) {
		printf("erro: insira o nome do arquivo e o tamanho do vetor aleatorio a ser ordenado\n");
		return 0;

	} else {
		
		int n = atoi(argv[1]);
		int* vec = NULL;
		
		srand(time(NULL));

		vec = (int*)malloc(sizeof(int)*n);
		
		for (int i = 0; i < n; i++)	{
			vec[i] = rand() % 10000;

		}
		
		heap_sort(vec, n);
		print_vec(vec, n);

		free(vec);

	}

return 0;	
}