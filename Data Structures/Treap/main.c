#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treap.h"

#define SPACE 32
#define ENTER 10


/* Função para realizar a leitura/armazenamento das strings, até que se seja o fim do arquivo(EOF) ou
   se chegue a condição de parada, que no caso é até um ENTER ou ESPAÇO ser pressionado/lido
  
  - parâmetros:
      int stopCond: condição de parada para a leitura

  - retorno:
      char*: ponteiro para a string recém alocada

*/
char* readLine(int stopCond){
  char *str = (char *)malloc(sizeof(char));
  char c; 
  int count = 0;

  do {
    c = fgetc(stdin);
    if(c != '\r'){
      str = (char *)realloc(str, sizeof(char) * (count + 1)); // a cada caractere armazenado, aloca-se memória para um próximo
      str[count++] = c;
    }

  } while(c != stopCond && c != EOF);
  str[count-1] = '\0';
  
  return str;
}


int main(){

  int numOps;               // armazena o número de operações a serem realizadas na árvore
  int key;                  // armazena a chave a ser inserida/removida/pesquisada
  int prio;                 // armazena a prioridade do nó a ser inserido/removido/pesquisado
  char* opName = NULL;      // aponta para a string que armazena o nome da operação a ser realizada na árvore
  t_tree *treap = create(); // criação da árvore treap

  scanf("%d\n", &numOps);

  for (int i = 0; i < numOps; i++) {
    opName = readLine(SPACE); // lê o nome da operação até que um espaço seja pressionado
    
    if(!strcmp(opName, "insercao")){
      scanf("%d %d\n", &key, &prio);
      insertion(treap, key, prio);
      
    } else if (!strcmp(opName, "remocao")){
      scanf("%d\n", &key);
      removal(treap, key);
      
    } else if (!strcmp(opName, "buscar")){
      scanf("%d\n", &key);      
      printf("%d\n", search(treap->root, key));

    } else if (!strcmp(opName, "impressao")){
      char* typeOfPrint = readLine(ENTER); // aponta para a string que armazena o tipo de impressão que será realizada

      if(!strcmp(typeOfPrint, "preordem")){
        preOrder(treap->root);
        printf("\n");

      } else if(!strcmp(typeOfPrint, "ordem")){
        inOrder(treap->root);
        printf("\n");

      } else if(!strcmp(typeOfPrint, "posordem")){
        postOrder(treap->root);
        printf("\n");

      } else if(!strcmp(typeOfPrint, "largura")){
        breadthPrint(treap->root);
      }      
      
      free(typeOfPrint); // desalocação da string para poder ser novamente usada em uma iteração futura
    }
    
    free(opName); // desalocação da string para uso futuro

  }
  
  freeTree(treap->root); // desalocação da árvore treap usada
  
  return 0;
}

