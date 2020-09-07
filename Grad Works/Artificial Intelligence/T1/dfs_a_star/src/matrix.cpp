#include "matrix.hpp"

void create_char_matrix(char ***matrix, int row, int col){
    (*matrix) = new char*[row];    
    for (int i = 0; i < row; i++)  (*matrix)[i] = new char[col];

}

void print_char_matrix(char **matrix, int row, int col){
    
    cout << endl;
    for (int i = 0; i <= row+1; i++) cout << "_";
    
    cout << endl;
    for (int i = 0; i < row; i++)  {
        cout << "|";
        for (int j = 0; j < col; j++)  {
        
            if(matrix[i][j] == 'o') cout << "\033[01;32m@\033[0m";
            else if(matrix[i][j] == 'I') cout << "\033[22;36m" <<  matrix[i][j] << "\033[0m";
            else if(matrix[i][j] == 'F') cout << "\033[01;32m" <<  matrix[i][j] << "\033[0m";
            else if(matrix[i][j] == 'X') cout << "\033[22;31m" <<  matrix[i][j] << "\033[0m";
            else if(matrix[i][j] == '_') cout << " ";
            else cout << matrix[i][j];
        }
        cout << "|"<< endl;
    }

    for (int i = 0; i <= row+1; i++) cout << "_";
    cout << endl;
}

void delete_char_matrix(char*** matrix, int row){
    for (int i = 0; i < row; i++) { 
        delete[] (*matrix)[i];
    }
    delete[] (*matrix);
    *matrix = NULL;
}

void read_char_matrix(char **matrix, int row, int col){
    for (int i = 0; i < row; i++)  {
        for (int j = 0; j < col; j++)  {
            cin >> matrix[i][j];
        }
        getchar();
    }
}


