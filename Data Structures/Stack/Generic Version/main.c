#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct point{
  int x, y;
  //char describe[100]; // nesse caso nao é bom fazer char* describe, pois haverá memory leak depois chamar o metodo destroy()
}point_t;

int main(int argc, char* argv[]){

  stack_t* p;
  int num, x;

  p = create(sizeof(point_t));
  point_t point;
  for (int i = 0; i < 10; i++){
    point.x = i;
    point.y = -i;
    push(p, &point);
  }
  

  while (!isEmpty(p)){
    pop(p, &point);
    printf("(%d %d) ", point.x, point.y);
  }
  
  printf("\n");
  destroy(p);

return 0;  
}