#include <stdio.h>
#include <stdlib.h>
#include "../include/stack.h"

int main(int argc, char* argv[]){

  STACK_PTR stk_ptr = NULL;

  create_stack(&stk_ptr);
  push(stk_ptr, 'e');
  push(stk_ptr, 'd');
  push(stk_ptr, 'z');
  push(stk_ptr, 'm');
  push(stk_ptr, 'i');
  push(stk_ptr, 'r');

  printf("top: %c\n", top(stk_ptr));
  printf("size: %d\n", size(stk_ptr));
  printStack(stk_ptr);

  
  printf("removed node: %c\n", pop(stk_ptr));
  printf("size: %d\n", size(stk_ptr));
  printStack(stk_ptr);
  

  free_stack(stk_ptr);



  return 0;  
}