#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "skiplist.h"

#define ENTER 10
#define SPACE 32

void readLine(int stop_cond, char* str){
  char c; 
  int count = 0;

  do {
    c = fgetc(stdin);
    if(c != '\r'){
      str[count++] = c;
    }

  } while(c != stop_cond && c != EOF);
  str[count-1] = '\0';
    
}


int main(){

  srand((unsigned)time(NULL));
  clock_t t0, t1, t2, t3;
  
  // time measure for each relevant operation
  double time_taken_by_insertion = 0.000000;
  double time_taken_by_removal = 0.000000;
  double time_taken_by_search = 0.000000;
  double time_taken_by_alteration = 0.000000;
  
  
  char *entry = (char*) malloc(sizeof(char) * 40);
  char *definition = (char *)malloc(sizeof(char) * 150);
  char *op = (char*) malloc(sizeof(char) * 11);
  char *ch = (char*)malloc(sizeof(char) * 2);

  skiplist *s_list = create();


  while (!feof(stdin)) { // ocorrerá até o final do arquivo 
    readLine(SPACE, op);

    if(!strcmp(op, "insercao")){
      readLine(SPACE, entry);
      readLine(ENTER, definition);
    
      //if(insertion(s_list, entry, definition) != 1) printf("OPERACAO INVALIDA: erro na inserção\n");
      t0 = clock();
      if(insertion(s_list, entry, definition) != 1) printf("OPERACAO INVALIDA\n");
      t0 = clock() - t0;

      time_taken_by_insertion += ((double)t0) / CLOCKS_PER_SEC;


    }  else if(!strcmp(op,"remocao")){
      readLine(ENTER, entry);

      //if(removal(s_list, entry) != 1) printf("OPERACAO INVALIDA: erro na remoção\n");
      t1 = clock();
      if(removal(s_list, entry) != 1) printf("OPERACAO INVALIDA\n");
      t1 = clock() - t1;
      time_taken_by_removal += ((double)t1) / CLOCKS_PER_SEC;



    }  else if(!strcmp(op,"alteracao")){
      readLine(SPACE, entry);
      readLine(ENTER, definition);
    
      //if(alteration(s_list, entry, new_definition) != 1) printf("OPERACAO INVALIDA: erro na alteração\n");
      t2 = clock();
      if(alteration(s_list, entry, definition) != 1) printf("OPERACAO INVALIDA\n");
      t2 = clock() - t2;
      time_taken_by_alteration += ((double)t2) / CLOCKS_PER_SEC;

    }  else if(!strcmp(op,"busca")){
      t_node* aux;
      readLine(ENTER, entry);

      t3 = clock();
      aux = search(s_list, entry);
      t3 = clock() - t3;
      time_taken_by_search += ((double)t3) / CLOCKS_PER_SEC;

      if(aux != NULL) printf("%s %s\n", aux->entry, aux->definition);
      else {
        //printf("OPERACAO INVALIDA: erro na busca\n");
        printf("OPERACAO INVALIDA\n");
        
      }
    
    } else if(!strcmp(op,"impressao")){
      readLine(ENTER, ch);
      
      if(print_list(s_list, ch) != 1) printf("NAO HA PALAVRAS INICIADAS POR %c\n", ch[0]);
      ch[0] = '\0';
    
    }
    
    
    op[0] = '\0';
    entry[0] = '\0';
    definition[0] = '\0';

  }

  //print_list(s_list, NULL);

  
  //double time_taken_by_insertion = ((double)t) / CLOCKS_PER_SEC; // calculate the elapsed time
  printf("The insertion took %f seconds to execute\n", time_taken_by_insertion);
  printf("The removal took %f seconds to execute\n", time_taken_by_removal);
  printf("The search took %f seconds to execute\n", time_taken_by_search);
  printf("The alteration took %f seconds to execute\n", time_taken_by_alteration);
  printf("number of skiplist nodes: %d\n", numberOfNodes(s_list));
  

  // frees
  free(entry);
  free(definition);
  free(ch);
  free(op);

  return 0;
}
