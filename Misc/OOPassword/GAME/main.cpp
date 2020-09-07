/*
* =====================================================================================
*
*       Filename:  main.c
*
*    Description:  Jogo OOPassword, desenvolvido para a disciplina
*									 SSC0103 - PROGRAMAÇÃO ORIENTADA A OBJETOS.
*
*									 		O jogo consiste em o jogador adivinhar uma sequência de letras
*									 formulada pelo computador. A cada tentativa, é informada a quantidade
*									 de letras acertadas e quantas delas estão nas posições corretas.
*									 		Há também uma versão onde o computador tenta acertar uma senha formulada
*									 pelo jogador.
*									 Bom divertimento! :)
*
*        Version:  1.0
*        Created:  08/06/2018 18:24:19
*       Revision:  25/06/2018
*       Compiler:  g++
*
*         Authors:  Eduardo Zaboto Mirolli (9778501)
* 									Paulo Bodnarchuki (9790944)
*
* =====================================================================================
*/

#include <iostream>
#include <iterator>
#include <vector>

#include "defVals.h"
#include "Game.h"
#include "Guess.h"

using namespace std;

int main() {

		cout << "OOPassword - ";
		cout << "ICMC-USP - ";
		cout << "Versao 1.0\n\n" << endl;
		cout << "Seja bem-vindo a OOPassword! :D" << endl;
		cout << "Desafio você a acertar a minha senha!!" << endl;
		cout << "Ou aposto que eu adivinho a sua! Vamos nessa??\n" << endl;

		bool playAgain = true;

		while (playAgain) {
			char choice = ' ';
			Game *g = new Game;
			g->Play();

			delete g;

			while (choice != 's' && choice != 'n') {
				cout << "\nQuer jogar novamente? (s/n): ";
				cin >> choice;
			}

			playAgain = choice == 's' ? true : false;
		}

		return 0;
}
