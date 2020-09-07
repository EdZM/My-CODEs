#include <iostream>
#include "matrix.hpp"

using namespace std;

void create_char_matrix(char ***matrix, int row, int col){
    (*matrix) = new char*[row];    
    for (int i = 0; i < row; i++)  (*matrix)[i] = new char[col];

}

void print_char_matrix(char **matrix, int row, int col){
    
    cout << endl;
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

void read_char_matrix(char **matrix, int row, int col){
    for (int i = 0; i < row; i++)  {
        for (int j = 0; j < col; j++)  {
            cin >> matrix[i][j];
        }
        getchar();
    }
}

