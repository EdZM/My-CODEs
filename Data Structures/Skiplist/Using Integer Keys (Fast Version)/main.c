#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "skiplist.h"

#define ENTER 10
#define SPACE 32

char* readLine(int stop_cond){
  char* str = NULL;
  char c; 
  int count = 0;

  do {
    c = fgetc(stdin);
    str = (char*)realloc(str, sizeof(char)*(count+1));
    str[count++] = c;

  } while(c != stop_cond && c != EOF);

  str[count-1] = '\0' ;
  return str;
}


int main(){
  
  srand((unsigned)time(NULL));
  
  char *op = NULL;
  char *entry = NULL;
  char *definition = NULL;
  int i = 0;
  double time_taken = 0.000000;
  skiplist* s_list = create();

  //printf("levels: %d\n", random_level());
  //printf("levels: %d\n", random_level());
  //printf("levels: %d\n", random_level());

  clock_t t1;
  t1 = clock();

  if(insertion(s_list, 10) != 1)printf("OPERARACAO INVALIDA\n");
  if(insertion(s_list, 20) != 1)printf("OPERARACAO INVALIDA\n");
  if(insertion(s_list, 15) != 1)printf("OPERARACAO INVALIDA\n");
  
  int num;
  // for (int i = 0; i <= 50000; i++) {
    
  //   //insertion(s_list, rand()%50000);
  //   scanf("%d", &num);
  //   insertion(s_list, num);
  // }


  print_list(s_list);
  printf("levels on skiplist %d\n", total_levels(s_list));
  printf("\n\n");


  if(removal(s_list, 12) != 1) printf("OPERARACAO INVALIDA\n");
  print_list(s_list);
  printf("levels on skiplist %d\n", total_levels(s_list));

  // t_node* aux;
  
  // for (int i = 50000; i >= 0; i--) {
  //   aux = search(s_list, i);
  //   if(aux != NULL) printf("%d\n", aux->key);
  //   else printf("OPERARACAO INVALIDA\n");
  // }
  
  
  //print_list(s_list);

  t1 = clock() - t1;
  time_taken += ((double)t1) / CLOCKS_PER_SEC;

  printf("The operations took %f seconds to execute\n", time_taken);
  
  

  //printf("%d\n", total_levels(s_list));
  //print_list(s_list);
  
  
  //insertion(s_list, 15);

  // while (!feof(stdin)) { // ocorrerá até o final do arquivo 
  //   op = readLine(SPACE);

  //   if(!strcmp(op, "insercao")){
  //     entry = readLine(SPACE);
  //     definition = readLine(ENTER);
  //     printf("op: %s\n", op);
  //     printf("entry: %s\n", entry);
  //     printf("definition: %s\n\n", definition);

  //     // inserção: To do

  //   } else if(!strcmp(op,"remocao")){
  //     entry = readLine(ENTER);
  //     printf("op: %s\n", op);
  //     printf("entry: %s\n\n", entry);

  //     // remoção: To do

  //   } else if(!strcmp(op,"alteracao")){
  //     entry = readLine(SPACE);
  //     definition = readLine(ENTER);
  //     printf("op: %s\n", op);
  //     printf("entry: %s\n", entry);
  //     printf("definition: %s\n\n", definition);

  //     // alteração: To do
      
  //   } else if(!strcmp(op,"busca")){
  //     entry = readLine(ENTER);
  //     printf("op: %s\n", op);
  //     printf("entry: %s\n\n", entry);

  //     // busca: To do

  //   } else if(!strcmp(op,"impressao")){
  //     entry = readLine(ENTER);
  //     printf("op: %s\n", op);
  //     printf("entry: %s\n\n", entry);

  //     // impressão: To do

  //   } else {
  //     printf("OPERACAO INVALIDA\n\n"); // pode retirar depois de finalizado o trabalho
    
  //   }

  //   // desalocações feitas após cada operação
  //   free(op);
  //   if(entry != NULL) {
  //     free(entry);
  //     entry = NULL;  
  //   }

  //   if(definition != NULL) {
  //     free(definition);
  //     definition = NULL;
  //   }
  // }

  return 0;
}
