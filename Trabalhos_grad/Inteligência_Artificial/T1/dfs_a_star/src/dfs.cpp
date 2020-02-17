#include <iostream>
#include <queue>
#include <vector>
#include "matrix.hpp"
#include "dfs.hpp"

using namespace std;

typedef struct PAIR PAIR;

struct PAIR{
    int row;
    int col;
};


void depth_walk(char** lab, vector<PAIR>* path, int row, int col, int i, int j, int* end_flag, PAIR destiny, float* cost){

    lab[i][j] = '-';
    
    PAIR coords;
    coords.row = i;
    coords.col = j;

    path->push_back(coords);
    
    if( destiny.row == i && destiny.col == j) (*end_flag) = 1;
    
    if ((*end_flag) != 1){
        // cima
        if( (i-1 >= 0) && lab[i-1][j] == '_' && (*end_flag) != 1) {
            depth_walk(lab, path ,row, col, i-1 , j, end_flag, destiny, cost);
            if((*end_flag) == 1){
                (*cost)++;
                lab[i][j] = 'o'; // a solução encontrada é marcada com o( nao necessariamente é a melhor)
            }
        }
        
        // diagonal para cima direita
        if( (i-1 >= 0 && j+1 <= col-1) && lab[i-1][j+1] == '_' && (*end_flag) != 1) {
            depth_walk(lab, path ,row, col, i-1 , j+1, end_flag, destiny, cost);
            if((*end_flag) == 1){
                (*cost) += 1.4;
                lab[i][j] = 'o'; // a solução encontrada é marcada com o( nao necessariamente é a melhor)
            }
        }

        //direita  
        if( (j+1 <= col-1) &&  lab[i][j+1] == '_' && (*end_flag) != 1) {
            depth_walk(lab, path ,row, col, i , j+1, end_flag, destiny, cost);        
            if((*end_flag) == 1){
                (*cost)++;
                lab[i][j] = 'o'; // a solução encontrada é marcada com o( nao necessariamente é a melhor)
            }
        }
        
        // diagonal para baixo direita
        if( (i+1 <= row -1 && j+1 <= col -1) && lab[i+1][j+1] == '_' && (*end_flag) != 1) {
            depth_walk(lab, path ,row, col, i+1 , j+1, end_flag, destiny, cost);
            if((*end_flag) == 1){
                (*cost) += 1.4;
                lab[i][j] = 'o'; // a solução encontrada é marcada com o( nao necessariamente é a melhor)
            }
        }

        //baixo
        if( (i+1 <= row-1) &&  lab[i+1][j] == '_' && (*end_flag) != 1 ) {
            depth_walk(lab, path, row, col, i+1, j, end_flag, destiny, cost);
            if((*end_flag) == 1){
                (*cost)++;
                lab[i][j] = 'o'; // a solução encontrada é marcada com o( nao necessariamente é a melhor)
            }       
        }

        // diagonal para baixo esquerda
        if( (i+1 <= row-1 && j-1 >= 0) && lab[i+1][j-1] == '_' && (*end_flag) != 1) {
            depth_walk(lab, path ,row, col, i+1 , j-1, end_flag, destiny, cost);
            if((*end_flag) == 1){
                (*cost) += 1.4;
                lab[i][j] = 'o'; // a solução encontrada é marcada com o( nao necessariamente é a melhor)
            }
        }

        //esquerda
        if( (j-1 >= 0) &&  lab[i][j-1] == '_' && (*end_flag) != 1) {
            depth_walk(lab, path, row, col, i, j-1, end_flag, destiny, cost);
            if((*end_flag) == 1){
                (*cost)++;
                lab[i][j] = 'o'; // a solução encontrada é marcada com o( nao necessariamente é a melhor)
            }
        }

        // diagonal para cima esquerda
        if( (i-1 >= 0 && j-1 >= 0) && lab[i-1][j-1] == '_' && (*end_flag) != 1) {
            depth_walk(lab, path ,row, col, i-1 , j-1, end_flag, destiny, cost);
            if((*end_flag) == 1){
                (*cost) += 1.4;
                lab[i][j] = 'o'; // a solução encontrada é marcada com o( nao necessariamente é a melhor)
            }
        }


        if((*end_flag) != 1) {
            path->pop_back();
            lab[i][j] = 'X'; // os caminhos que levam a becos são marcados com X
        }
        
    } else {
        lab[destiny.row][destiny.col] = 'F';
        return;

    }
    

}

void depth_first_search(char **lab, int row, int col) {

    vector<PAIR> path;
    PAIR origin;
    PAIR destiny;
    int end_flag = 0;
    float cost = 0;

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if(lab[i][j] == 'I') {
                origin.row = i; 
                origin.col = j;
            }
            if(lab[i][j] == 'F') {
                destiny.row = i; 
                destiny.col = j;
                lab[i][j] = '_';
            }
        }
    }

    depth_walk(lab, &path, row, col, origin.row, origin.col, &end_flag, destiny ,&cost);
     
    


    /* PARA IMPRIMIR O CAMINHO GERADO DESCOMENTE AS LINHAS ABAIXO*/
    // cout << "Origem: ( " << origin.row << ", " << origin.col << " ) " << endl;
    // cout << "Destino: ( " << destiny.row << ", " << destiny.col << " ) " << endl << endl;
    // cout << "Caminho até o destino: elementos "<< path.size() << endl;
    // for ( vector<PAIR>::iterator it = path.begin() ; it != path.end(); it++){
    //     cout << "( " << it->row << ", " << it->col << " ) "; 
    // }
    // cout << endl;

    lab[origin.row][origin.col] = 'I';

    // Impressão do labirinto já percorrido.
    print_char_matrix(lab, row, col);

    // cout << cost << endl;
    // cout << path.size() << endl;
    cout << "Custo: " << cost << endl;
    cout << "Quantidade de elementos que formam o caminho até o destino: " << path.size() << endl;

   
}



