#include <stdio.h>
#include "queue.h"


int main(){

  QUEUE* queue = NULL;
  
  create_queue(&queue);

  enqueue(queue, 10);
  // enqueue(queue, 15);
  // enqueue(queue, 20);
  // enqueue(queue, 25);
  // enqueue(queue, 30);
  // enqueue(queue, 35);
  // enqueue(queue, 40);
  // enqueue(queue, 45);
  // enqueue(queue, 50);
  // enqueue(queue, 55);
  //enqueue(queue, 55); // overflow test

  
  printQueue(queue);
  printf("removed node: %d\n", dequeue(queue));
  printf("removed node: %d\n", dequeue(queue));

  printQueue(queue);
  
  freeQueue(&queue);

  return 0;
}