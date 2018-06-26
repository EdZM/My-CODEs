/*=================================================================================================================================

Arquivo com as funções da biblioteca GUESS, que será responsavel por gerenciar as tentativas fornecidas pelo jogador. Tem metodos 
relevantes como os de mostrar a tentativa, contabilizar os acertos, dentre outras funções 



==================================================================================================================================*/


#ifndef GUESS_H
#define GUESS_H

#include "definedValues.h"
#include "storable.h"

class Reader;
class Writer;

class Guess : public Storable{
public:
	Guess(vector<char>guess, int howManyRight, int howManyInPosition);
	Guess(Reader & rdr);
	virtual ~Guess(){}
	void Display()	const;
	pair<int, int> GetScore() const;
	vector<char>GetString()	const;
	virtual void Write(Writer&) const;

private:
	pair<int, int> score;
	vector<char> string;
};

#endif