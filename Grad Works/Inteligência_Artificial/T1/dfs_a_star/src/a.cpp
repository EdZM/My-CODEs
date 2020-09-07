#include <iostream>
#include <queue>
#include <vector>
#include "matrix.hpp"
#include "a.hpp"

using namespace std;


typedef struct PAIR PAIR;

struct PAIR{
    int row;
    int col;
    //queue<PAIR> path;
    int cost;

};



double cost = 0;

// caminho padrão = *
// parede = -
// Início = #
// Chegada = $

PAIR init_point(char **lab, int row, int col){
    PAIR init;

    init.row = 0;
    init.col = 0;
    init.cost = 0;

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(lab[i][j] == 0) {
                init.row = i;
                init.col = j;

                return init;
            }
        }
    }

    return init;
}


//void print_path(queue<PAIR> path) {
//    PAIR coordinates;
//
//    cout << "||| Path: ";
//    while(!path.empty()) {
//        coordinates = path.front();
//        path.pop();
//        cout << "(" << coordinates.row << ", " << coordinates.col << ") ";
//
//    }
//    cout << "|||" << endl;
//} 

int valid_path(char **lab, int row, int col, int new_row, int new_col) {
        if(new_row >= 0 
            && new_row < row
            && new_col >= 0
            && new_col < col
            && (lab[new_row][new_col] == '*' || lab[new_row][new_col] == '$')) {

            return 1;
        
        } else return 0;
}

void queue_position(queue<PAIR>& fila, int row, int col, int cost, char **lab) {
    PAIR new_position;
    new_position.row = row;
    new_position.col = col;
    new_position.cost = cost;

    fila.push(new_position);

    if(lab[row][col] == '*') lab[row][col] = '0';

    return;
}


void breadth_walk(char **lab, int row, int col, PAIR position, queue<PAIR>& fila){
    //printf("Entrou na posicao (%d, %d)\n", position.row, position.col);
    cout << "Entrou na posicao: (" << position.row << ", " << position.col <<")" << endl;
    //position.path.push(position);
    
    cost += position.cost;

    // up
    if(valid_path(lab, row, col, position.row-1, position.col)) {
        queue_position(fila, position.row-1, position.col, 1, lab); 
    }
    // up-right
    if(valid_path(lab, row, col, position.row-1, position.col+1)) {
        queue_position(fila, position.row-1, position.col+1, 1, lab); 
    }
    // right
    if(valid_path(lab, row, col, position.row, position.col+1)) {
        queue_position(fila, position.row, position.col+1, 1, lab); 
    }
    // down-right
    if(valid_path(lab, row, col, position.row+1, position.col+1)) {
        queue_position(fila, position.row+1, position.col+1, 1, lab); 
    }
    // down
    if(valid_path(lab, row, col, position.row+1, position.col)) {
        queue_position(fila, position.row+1, position.col, 1, lab); 
    }
    // left-down
    if(valid_path(lab, row, col, position.row+1, position.col-1)) {
        queue_position(fila, position.row+1, position.col-1, 1, lab); 
    }
    // left
    if(valid_path(lab, row, col, position.row, position.col-1)) {
        queue_position(fila, position.row, position.col-1, 1, lab); 
    }
    // up-left
    if(valid_path(lab, row, col, position.row-1, position.col-1)) {
        queue_position(fila, position.row-1, position.col-1, 1, lab); 
    }

    return;

}

void breadth_first_search(char **lab, int row, int col){
    queue<PAIR> fila;
    PAIR init = init_point(lab, row, col);
    PAIR position;
    cost = 0;

    fila.push(init);
    while(!fila.empty()) {
        position = fila.front();
        fila.pop();
        if (lab[position.row][position.col] != '$') {
            breadth_walk(lab, row, col, position, fila);
        } else {
            //position.path.push(position);
            //print_path(position.path);
            print_char_matrix(lab, row, col);
            cout << "||| Cost: " << cost << " |||" << endl;
            return;
        }
        //print_char_matrix(lab, row, col);
    }
    //print_char_matrix(lab, row, col);
    
    return;
}

