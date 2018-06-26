#include "Decrypter.h"
#include "Game.h"

Decrypter::Decrypter(bool hasDuplicates):
duplicates(hasDuplicates),
round(1)
{

}

Decrypter::Decrypter(Reader & rdr):
Storable(rdr)
{
	rdr >> round;
	rdr >> duplicates;
	int size;
	rdr >> size;
	for ( int i = 0; i < size; i++)
	{
		Guess theGuess(rdr);
		history.push_back(theGuess);
	}
}

Decrypter::~Decrypter()
{

}


void Decrypter::Display(vector<char> charVec) const{ 
	copy( charVec.begin(), charVec.end(), ostream_iterator<char>(cout," ") ); 
}

// Iterar no historico de tentaticas e mostrar os resultados
void Decrypter::ShowHistory(){
	for (vector<Guess>::const_iterator it = history.begin(); it != history.end(); it++)	{
		it->Display();
	}
}

void Decrypter::Write(Writer & wrtr) const{
	wrtr << round;
	wrtr << duplicates;
	int len = history.size();
	wrtr << len;
	for (vector<Guess>::const_iterator it = history.begin(); it != history.end(); it++){
		it->Write(wrtr);
	}
}



