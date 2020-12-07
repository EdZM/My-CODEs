
#include <stdio.h>
#include <stdlib.h>
#include "b_list.h"

int main(){
 
  int time = 0;   // contagem discreta de tempo, que será alterada por referência
  int n;          // especifica a chave do nó que será removido ou inserido
  int j;          // especifica o número de posições antes de um nó inserido
  char op = 'x';  // especifica a operação realizada por linha
  
  b_list* l_backward = create();

  while (op != 'f') { // Enquanto um f de finalizar não for digitado, as operações ainda poderão ser feitas
    scanf("%c", &op);

    if ( op == 'i' ) { // i == inserção
      scanf("%d %d", &n, &j);
      insertion(l_backward, n, j, &time);

    } else if(op == 'r'){ // r == remoção
      scanf("%d", &n);
      removal(l_backward, n, &time);
    
    }
    
  }

  print_list(l_backward);

  free_list(l_backward);


  return 0;
}





