#include <iostream>
#include <iterator>
#include <vector>

#include "defVals.h"
#include "Game.h"
#include "Guess.h"

using namespace std;

int main(){

	cout << "OOPassword - ";
	cout << "ICMC-USP - ";
	cout << "Version 1.0\n\n" << endl;
	cout << "Seja bem-vindo ao OOPassword! :D" << endl;
	cout << "Desafio você a acertar a minha senha" << endl;
	cout << "ou aposto que eu adivinho a sua. Vamos nessa?\n\n" << endl;

	bool playAgain = true;

	while ( playAgain ){
		char choice = ' ';
		Game * g = new Game;
		g->Play();

		delete g;

		while ( choice != 's' && choice != 'n' )
		{
			cout << "\nJogar novamente (s/n): ";
			cin >> choice;
		}

		playAgain = choice == 's' ? true : false;
	}

	return 0;
}
