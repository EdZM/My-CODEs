#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <ctime>

using namespace std;

typedef struct PAIR PAIR;

struct PAIR{
    int row; 
    int col;

};



void create_char_matrix(char ***matrix, int row, int col){
    (*matrix) = new char*[row];    
    for (int i = 0; i < row; i++)  (*matrix)[i] = new char[col];

}

void print_char_matrix(char **matrix, int row, int col){
    
    cout << row << " " << col << endl;
    for (int i = 0; i < row; i++)  {
        for (int j = 0; j < col; j++)  {
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void delete_char_matrix(char*** matrix, int row){
    for (int i = 0; i < row; i++) { 
        delete[] (*matrix)[i];
    }
    delete[] (*matrix);
    *matrix = NULL;
}

int main(int argc, char* argv[]){

    int coin;
    
    if(argc == 3){
        int row = atoi(argv[1]) , col = atoi(argv[2]) ;
        char** lab_mat;
        vector<PAIR> neighbours; 
        PAIR coords;

        srand(time(NULL));

        create_char_matrix(&lab_mat, row, col);

        for (int i = 0; i < row; i++)  {
            for (int j = 0; j < col; j++)  {
                lab_mat[i][j] = '#';
            }
            
        }

        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (i > 1 ) {
                    coords.row = i-1;
                    coords.col = j;
                    neighbours.push_back(coords);
                    
                }
                if (j > 1){
                    coords.row = i;
                    coords.col = j-1;
                    neighbours.push_back(coords);
                }
            
            
                if(neighbours.empty()) continue;
                    
                coin = rand() % neighbours.size();
                PAIR pos = neighbours[coin];
                lab_mat[pos.row][pos.col] = '_';
                
                while(!neighbours.empty()){
                    neighbours.pop_back();
                }

            }            
        }
        
        print_char_matrix(lab_mat, row, col);
        delete_char_matrix(&lab_mat, row);

    } else {
        cout << "type: ./random_maze <rows> <cols>" << endl;
    
    }

return 0;    
}
