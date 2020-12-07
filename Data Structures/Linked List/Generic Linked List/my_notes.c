/*


- Formalmente: Uma lista generalizada A tem numero finito de elementos, sendo que podem ser átomos ou listas


Lista generalizada tem:
  -> cabeça: primeiro elemento da lista(átomo ou lista)
  -> cauda: o restante da lista, ainda que esteja vazia


3 informações por nó:
  -> tipo de dado: informa se o nó é átomo ou sublista
  -> átomos ou ponteiros para a sublista                  (+ FÁCIL DE ENTENDER)
  -> ponteiro para o próximo elemento

      OU
  
  -> tipo de dado: informa se o nó é átomo(indicado pelo valor 0) ou sublista (indicado pelo valor 1)
  -> a cabeça: primeiro elemento
  -> ponteiro para a cauda


representação

  (1,2,3) ou [1,2,3]

  (1,(2,3)) ou [1, [2,3]]
  
  (1,(2),(3)) ou [1, [2],[3]]






*/