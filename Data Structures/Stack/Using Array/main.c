#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char* argv[]){

  stack_t* p;
  int num, x;

  p = create();
  
  scanf("%d", &num);
  
  while(num > 0){
    push(p, num % 2);
    num /= 2;
  }

  while (!isEmpty(p)){
    pop(p, &x);
    printf("%d", x);
  }
  
  printf("\n");
  destroy(p);

return 0;  
}