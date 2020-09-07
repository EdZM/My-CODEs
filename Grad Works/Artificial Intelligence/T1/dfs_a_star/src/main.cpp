/*
* =========================================================================================================================================================
*       Trabalho 1 de Inteligência Artificial
*       Nome do arquivo:  T1_IA.c
*
*       Descrição:  
*                   
*
*       Nome:  Eduardo Zaboto Mirolli 
*       Nº USP:  9778501
*
*       Nome:  Paulo H. B. da Cruz
*       Nº USP:  9790944
*
*       Nome: Beatriz Monteiro
*       Nº USP:  9778619  
*
* =========================================================================================================================================================
*/

#include "matrix.hpp"
#include "dfs.hpp"
#include "bfs.hpp"
#include "a.hpp"
#include "a_star.hpp"
#include <chrono>


int main(int argc, char* argv[]){

    int row, col, op;
    char** lab = NULL;
    
    op = atoi(argv[1]);
    
    if(argc == 2){ 
        cin >> row >> col;

        create_char_matrix(&lab, row, col);
        read_char_matrix(lab, row, col);

        cout << endl;
        cout << "Antes de aplicar a busca: " << endl;
        print_char_matrix(lab, row, col);

        auto start = std::chrono::high_resolution_clock::now();

        if(op == 1) depth_first_search(lab, row, col);
        //if(op == 2) breadth_first_search(lab, row, col);
        //if(op == 3) best_first_search(lab, row, col);
        if(op == 4) a_star_search(lab, row, col);

        auto finish = std::chrono::high_resolution_clock::now();

        // cálculo do tempo decorrido em segundos
        std::chrono::duration<double> elapsed = finish - start;

        double time = elapsed.count();


        cout << "time elapsed: " << time << "s"<< endl;
        //cout << time << endl;

        delete_char_matrix(&lab, row);
    
    } else {
        cout << "type: ./main <search_op(1-4)>" << endl;


    }
return 0;      
}
