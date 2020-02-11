#include <stdlib.h>
#include <limits.h>
#include "matrix.h"
#include <stdio.h>

//Quicksort adaptado de //https://www.geeksforgeeks.org/quick-sort/
int partition (int *arr, int low, int high, int C){
    int i, j;
    double pivot,swap;
    
    // pivot (Element to be placed at right position)
    pivot = arr[high*C];  
 
    i = (low - 1);  // Index of smaller element

    for (j = low; j <= high-1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j*C] <= pivot)
        {
            i++;    // increment index of smaller element
            
            // swap arr[i] and arr[j]
            swap = arr[i*C];
	    arr[i*C] = arr[j*C];
	    arr[j*C] = swap;
        }
    }
    
    //swap arr[i + 1] and arr[high]
    swap = arr[(i + 1)*C];
    arr[(i + 1)*C] = arr[high*C];
    arr[high*C] = swap;
    
    return (i + 1);
  
} // fim partition


/* low  --> Starting index,  high  --> Ending index */
void quicksort(int *arr, int low, int high, int C){
    int pi;
    
    if (low < high)  {
        /* pi is partitioning index, arr[pi] is now
           at right place */
        pi = partition(arr, low, high, C);

        quicksort(arr, low, pi - 1, C);  // Before pi
        quicksort(arr, pi + 1, high, C); // After pi
    }
    
} // fim quicksort


void rearranjar_heap(int *v, int i, int tamanho_heap) {
    int menor, aux;
    int esq = 2*i+1;
    int dir = 2*i+2;
    
    if ((esq < tamanho_heap) && (v[esq] < v[i]))
        menor = esq;
    else 
        menor = i;

    if((dir < tamanho_heap) && (v[dir] < v[menor]))
        menor = dir;
    
    if (menor != i) {
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
        rearranjar_heap(v, menor, tamanho_heap);
    }

    return;
}

void construir_heap(int *v, int n) {
    int i;
    for (i = (n/2)-1; i >= 0; i--) {
        rearranjar_heap(v, i, n);
    }

    return;
}

int source_list(int **info, int valor, int k) {
    for (int i = 0; i < k; i++) {
        if (valor == info[i][0]) {
            return i;
        }
    }
    return 0;
}

void intercal(int **matrix, int *v, int k, int n) {
    int list;

    int *heap = (int *) malloc(k * sizeof(int));
    for(int i = 0; i < k; i++) {
        heap[i] = matrix[i][0];
        
    }
    construir_heap(heap, k);
    int **info = (int **) malloc(k * sizeof(int *));

    for(int i = 0; i < k; i++) {
        info[i] = (int *) malloc(2 * sizeof(int));
        info[i][0] = matrix[i][0];
        info[i][1] = 1;
    }


    for (int i = 0; i < n*k; i++) {
        v[i] = heap[0];
        list = source_list(info, v[i], k);
        if (info[list][1] < n) {
            heap[0] = matrix[list][info[list][1]++];
        } else {
            heap[0] = INT_MAX;
        }
        info[list][0] = heap[0];
        
        rearranjar_heap(heap, 0, k);
    }

    free_matrix(&info, k);
    free(heap);

    return;
}