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

// MergeSort (ou ordenação por mistura, versão iterativa).
// OBS.: Usa o paradigma da divisão e conquista 
void merge_sort(int *a, int n) {

	int *buf = (int *) malloc(sizeof(int) * n); //vetor auxiliar para a ordenação

	if (buf == NULL) {
		exit(-2);
	}
	
	int block_len;
	
	for(block_len = 1; block_len < n; block_len *= 2) { 
		
		int pos = 0;
		for(pos = 0; pos < n; pos++) { 
			buf[pos] = a[pos];
			atrib_counter++;
		}
		pos = 0;
		while(pos < n) { 
			int cl1 = pos;
			int cl2 = cl1 + block_len;
			int fl1 = cl1 + block_len;
			int fl2 = cl2 + block_len;
			if (fl1 > n) { //util quando estou comparando blocos de tamanhos diferentes (como ira acontecer se o vetor tiver numero impar de posições) 
				fl1 = n;
			}
			if (fl2 > n) {
				fl2 = n;
			}
			while(cl1 < fl1 && cl2 < fl2) { // controla o até onde vai cada lista (1 e 2) 
				comp_counter++;
				if (buf[cl1] <= buf[cl2]) {
					a[pos++] = buf[cl1++];
				} else {
					a[pos++] = buf[cl2++];
				}
				atrib_counter++;
			}

			// esses 2 whiles a seguir preenchem o vetor 'a' com as posições restantes de 'buf' em caso de os blocos serem de tamanhos diferentes
			while(cl1 < fl1) { 
				a[pos++] = buf[cl1++];
				atrib_counter++;
			}
			
			while(cl2 < fl2) {
				a[pos++] = buf[cl2++];
				atrib_counter++;
			}
		}
	}
	

free(buf);
}


int main( int argc , char* argv[]){

	
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

	merge_sort(a, n);
	print_vec(a,  n);
	printf("Comparações feitas: %ld\n", comp_counter);
	printf("Atribuições feitas: %ld\n", atrib_counter);

free(a);
return 0;
}