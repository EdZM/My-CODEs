#include <iostream>
#include "searches.hpp"
#include "matrix.hpp"
#include <queue>

using namespace std;

typedef struct PAIR PAIR;

struct PAIR {
    int row;
    int col;
    //queue<PAIR> path;
    double cost;
    int distance;
    
};

struct CompareDistance { 
    bool operator()(PAIR const& p1, PAIR const& p2) 
    { 
        // return "true" if "p1" is ordered  
        // before "p2", for example: 
        return p1.distance < p2.distance; 
    } 
}; 

PAIR end_point;
double cost = 0;

// caminho padrão = _
// parede = #
// Início = I
// Chegada = F

PAIR init_point(char **lab, int row, int col){
    PAIR init;

    init.row = 0;
    init.col = 0;
    init.cost = 0;
    init.distance = 0;

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(lab[i][j] == 'I') {
                init.row = i;
                init.col = j;

                return init;
            }
        }
    }

    return init;
}

void find_end_point(char **lab, int row, int col){

    end_point.row = 0;
    end_point.col = 0;
    end_point.cost = 0;
    end_point.distance = 0;

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(lab[i][j] == 'F') {
                end_point.row = i;
                end_point.col = j;

                return;
            }
        }
    }

    return;
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
            && (lab[new_row][new_col] == '_' || lab[new_row][new_col] == 'F')) {

            PAIR position;
            position.row = new_row;
            position.col = new_col;

        
        } else return 0;
}

void queue_position(queue<PAIR>& fila, int row, int col, double cost, char **lab) {
    PAIR new_position;
    new_position.row = row;
    new_position.col = col;
    new_position.cost = cost;

    fila.push(new_position);

    if(lab[row][col] == '_') lab[row][col] = '0';

    return;
}

void breadth_walk(char **lab, int row, int col, PAIR position, queue<PAIR>& fila){
//    cout << "Entrou na posicao: (" << position.row << ", " << position.col <<")" << endl;
    //position.path.push(position);
    
    cost += position.cost;

    // up
    if(valid_path(lab, row, col, position.row-1, position.col)) {
        queue_position(fila, position.row-1, position.col, 1, lab); 
    }
    // up-right
    if(valid_path(lab, row, col, position.row-1, position.col+1)) {
        queue_position(fila, position.row-1, position.col+1, 1.4, lab); 
    }
    // right
    if(valid_path(lab, row, col, position.row, position.col+1)) {
        queue_position(fila, position.row, position.col+1, 1, lab); 
    }
    // down-right
    if(valid_path(lab, row, col, position.row+1, position.col+1)) {
        queue_position(fila, position.row+1, position.col+1, 1.4, lab); 
    }
    // down
    if(valid_path(lab, row, col, position.row+1, position.col)) {
        queue_position(fila, position.row+1, position.col, 1, lab); 
    }
    // left-down
    if(valid_path(lab, row, col, position.row+1, position.col-1)) {
        queue_position(fila, position.row+1, position.col-1, 1.4, lab); 
    }
    // left
    if(valid_path(lab, row, col, position.row, position.col-1)) {
        queue_position(fila, position.row, position.col-1, 1, lab); 
    }
    // up-left
    if(valid_path(lab, row, col, position.row-1, position.col-1)) {
        queue_position(fila, position.row-1, position.col-1, 1.4, lab); 
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
        if (lab[position.row][position.col] != 'F') {
            breadth_walk(lab, row, col, position, fila);
        } else {
            //position.path.push(position);
            //print_path(position.path);
            cout << cost << endl;
            return;
        }
        //print_char_matrix(lab, row, col);
    }
    //print_char_matrix(lab, row, col);
    cout << cost << endl;
    
    return;
}

void priority_queue_position(priority_queue<PAIR, vector<PAIR>, CompareDistance>& fila, int row, int col, double cost, char **lab) {
    PAIR new_position;
    new_position.row = row;
    new_position.col = col;
    new_position.cost = cost;
    new_position.distance = -((row-end_point.row)*(row-end_point.row) + (col-end_point.col)*(col-end_point.col));

    fila.push(new_position);

    if(lab[row][col] == '_') lab[row][col] = '0';

    return;
}

void best_first_walk(char **lab, int row, int col, PAIR position, priority_queue<PAIR, vector<PAIR>, CompareDistance>& fila){
//    cout << "Entrou na posicao: (" << position.row << ", " << position.col <<")" << endl;
    //position.path.push(position);
    
    cost += position.cost;

    // up
    if(valid_path(lab, row, col, position.row-1, position.col)) {
        priority_queue_position(fila, position.row-1, position.col, 1, lab); 
    }
    // up-right
    if(valid_path(lab, row, col, position.row-1, position.col+1)) {
        priority_queue_position(fila, position.row-1, position.col+1, 1.4, lab); 
    }
    // right
    if(valid_path(lab, row, col, position.row, position.col+1)) {
        priority_queue_position(fila, position.row, position.col+1, 1, lab); 
    }
    // down-right
    if(valid_path(lab, row, col, position.row+1, position.col+1)) {
        priority_queue_position(fila, position.row+1, position.col+1, 1.4, lab); 
    }
    // down
    if(valid_path(lab, row, col, position.row+1, position.col)) {
        priority_queue_position(fila, position.row+1, position.col, 1, lab); 
    }
    // left-down
    if(valid_path(lab, row, col, position.row+1, position.col-1)) {
        priority_queue_position(fila, position.row+1, position.col-1, 1.4, lab); 
    }
    // left
    if(valid_path(lab, row, col, position.row, position.col-1)) {
        priority_queue_position(fila, position.row, position.col-1, 1, lab); 
    }
    // up-left
    if(valid_path(lab, row, col, position.row-1, position.col-1)) {
        priority_queue_position(fila, position.row-1, position.col-1, 1.4, lab); 
    }

    return;

}

void best_first_search(char **lab, int row, int col){
    priority_queue<PAIR, vector<PAIR>, CompareDistance> fila;
    PAIR init = init_point(lab, row, col);
    find_end_point(lab, row, col);
    PAIR position;
    cost = 0;

    fila.push(init);
    while(!fila.empty()) {
        position = fila.top();
        fila.pop();
        if (lab[position.row][position.col] != 'F') {
            best_first_walk(lab, row, col, position, fila);
        } else {
            //position.path.push(position);
            //print_path(position.path);
            cout << cost << endl;
            return;
        }
        //print_char_matrix(lab, row, col);
    }
    //print_char_matrix(lab, row, col);
    cout << cost << endl;
    
    return;
}
