#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>


// Pra ver o tempo de execução, em milissegundos, dos metodos de ordenação digite no terminal--> time ./nome_do_programa  


// MergeSort (ou ordenação por mistura).
void merge(int a[], int n) {

	int *buf = (int *) malloc(sizeof(int) * n);

	if (buf == NULL) {
		exit(-2);
	}
	
	int block_len;
	
	for(block_len = 1; block_len < n; block_len *= 2) {
		
		int pos = 0;
		for(pos = 0; pos < n; pos++) { 
			buf[pos] = a[pos];
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
				if (buf[cl1] <= buf[cl2]) {
					a[pos++] = buf[cl1++];
				} else {
					a[pos++] = buf[cl2++];
				}
			}
			while(cl1 < fl1) { // esses whiles a seguir preenchem o vetor 'a' com as posições restantes de 'buf' em caso de os blocos serem de tamanhos diferentes
				a[pos++] = buf[cl1++];
			}
			
			while(cl2 < fl2) {
				a[pos++] = buf[cl2++];
			}
		}
	}

free(buf);
}

void print_vec(int vec[], int n){

	for (int i = 0; i < n; i++)	{
		printf("%d ", vec[i]);
	}	
	printf("\n");

}

int main( int argc , char* argv[]){

	if(argc != 2){
		printf("Digite o nome do arquivo seguido da quantidade de elementos\n");
		return 0;
	
	} else {

		int n = atoi(argv[1]);
		int* nums = NULL;
		
		nums = (int*) malloc(sizeof(int)*n);

		for (int i = 0; i < n; i++){
			nums[i]	= rand()%n;
		}

		merge(nums, n);
		print_vec(nums,n);
	
	}

return 0;
}