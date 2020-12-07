#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"


int main(int argc, char const *argv[]){

  QUEUE *queue = create_queue();
  srand(time(NULL));
  
  int count = 5;

  for (int i = 0; i < count; i++){
    int rand_num = rand()%1000;  
    enqueue(queue, rand_num);
  }

  print_queue(queue);
  printf("removed node: %d\n", dequeue(queue));
  print_queue(queue);


  free_queue(&queue);

return 0;
}