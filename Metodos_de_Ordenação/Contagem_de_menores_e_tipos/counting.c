#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void init(int a[], int n, int step, int range){
	
	srand(time(NULL));

	for (int i = 0; i < n; i++)	{
		int base = i * step;
		int offset = rand() % range;
		a[i] = base + offset;
	}
}

void print_vec(int vec[], int n){

	for (int i = 0; i < n; i++)	{
		printf("%d ", vec[i]);
	}	
	printf("\n");

}

void less_counting(int* a, int n){

	int* b = NULL;
	int count = 0;


	b = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++){
			b[i] = a[i];
	}	

	for (int i = 0; i < n; i++)	{
		count = 0;
		for (int j = 0; j < n; j++){
			if( i!=j && b[i] > b[j]){
				count++;
			}
			if( i>j && b[i] == b[j] ){
				count++;
			}
			
		}
		a[count] = b[i];

	}

	print_vec(a,n);

}

void type_counting(int* a, int n, int k){ //k é o número de tipos envolvidos
	
	int* types = NULL;
	int* aux = NULL;

	types = (int*)calloc(k,sizeof(int)); // já zera o vetor criado na heap
	aux = (int*)calloc(n,sizeof(int));

	for (int i = 0; i < n; i++){
		types[a[i]]++ ;

	}

	print_vec(types,k);

	for (int i = k - 1; i > 0; i--){
		types[i] = types[i-1];
	}
	types[0] = 0;

	print_vec(types,k);

	for (int i = 1; i < k; i++){
		types[i] += types[i-1];
	}

	print_vec(types,k);

	for (int i = 0; i < n; i++){
		
		aux[types[a[i]]] = a[i];
		types[a[i]]++;
	}

	print_vec(types,k);
	print_vec(aux,n);
	//print_vec(types,k);
	
}




int main(int argc, char const *argv[]){
	
	//if(argc == 2){
		int* a = NULL;
		//int n = atoi(argv[1]);
		int n = 9;
		int k = 10;
		
		a = (int*)malloc(sizeof(int)*n);
		
		//init(a, n , 0, 5*n);

		a[0] = 8;
		a[1] = 6;
		a[2] = 0;
		a[3] = 2;
		a[4] = 9;
		a[5] = 5;
		a[6] = 9;
		a[7] = 6;
		a[8] = 0; 
		 
		 

		//less_counting(a,n);
		//type_counting(a,n,k);
	
		free(a);

	//}else {
	//	printf("Insira: ./<nome_Programa> <numero_de_elementos>\n");

	//}

return 0;
}

/*exemplo

	a[0] = 71;
	a[1] = 61;
	a[2] = 44;
	a[3] = 3;
	a[4] = 26;
	a[5] = 82;
	a[6] = 59;
	a[7] = 40;
	a[8] = 0; 
	a[9] = 0; 
	a[10] = 56;
	a[11] = 37; 

*/