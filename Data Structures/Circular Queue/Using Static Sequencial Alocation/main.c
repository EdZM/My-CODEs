#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int main(int argc, char* argv[]){

  queue_t* fila;
  int elm;

  fila = create();

  for (int i = 0; i < 10; i++){
    insertion(fila, i);
  }

  removal(fila, &elm);
  printf("%d ", elm);
  removal(fila, &elm);
  printf("%d ", elm);

  insertion(fila, 11);


  while (!isEmpty(fila)){
    removal(fila, &elm);
    printf("%d ", elm);
  }
  
  printf("\n");
  return 0;  
}