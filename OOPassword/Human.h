/*=================================================================================================================================

Arquivo com as funções da biblioteca HUMAN, que será usada para gerenciar as tentativas, pontuações, dicas, ajudas, dentre outras
funções referentes ao jogador humano


==================================================================================================================================*/


#ifndef HUMAN_H
#define HUMAN_H

#include "Decrypter.h"

class Reader;
class Writer;

class Human : public Decrypter  {
public:
	Human  (bool duplicates);
	Human (Reader& rdr);
	virtual   ~Human ();

	vector<char> GetSolution() const; 
	bool   	HandleFlag (char flag, bool & isStoring);
	bool   	IsValid  (char c) const;
	bool   	Play();
	void   	Score( vector<char> thisGuess, int & correct, int & position );
	void	Store();

	virtual void Write(Writer& wrtr) const;

private:
	void   ShowHint ();
	void   ShowHelp ();

	int    hintCtr;
	vector<char> solution;
};

#endif 

