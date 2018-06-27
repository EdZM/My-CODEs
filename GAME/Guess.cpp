/*
	Implementação da classe Guess, responsável por gerenciar e
	verificar as tentativas vindas de qualquer jogador
*/

#include <iterator>
#include "Guess.h"

Guess::Guess(vector<char>guess, int howManyRight, int howManyInPosition):
myString(guess),
score(howManyRight, howManyInPosition) {

}

void Guess::Display() const {
		copy(myString.begin(), myString.end(), ostream_iterator<char>(cout," "));
		cout << "\t";
		cout << score.first;
		cout << " corretas, ";
		cout << score.second;
		cout << " na posicao" << endl;
}
