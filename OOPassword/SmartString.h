/*=================================================================================================================================

Arquivo com as funções da biblioteca SMARTSTRING, que será usada para gerenciar as tentativas do computador quando for ele quem estiver
jogando

==================================================================================================================================*/


#ifndef SMARTSTRING_H
#define SMARTSTRING_H

#include "definedValues.h"
#include "SmartChar.h"



class Guess;

class SmartString  {
public:
	SmartString(bool dupes);
	SmartString(Reader& rdr);
	virtual	~SmartString();

	bool CanEliminateCharacters	(const Guess& theGuess);
	bool GetNext();
	vector<char> GetString();
	bool RemoveCurrentCharacters();
	bool RemoveCurrentCharactersInEveryPosition();
	void Write(Writer& wrtr) const;


private:

	void ForceCharacters(const Guess & theGuess);
	int	CountForcedInGuess(const Guess & theGuess);
	int	CountUniqueLettersInGuess(const Guess & theGuess);
	bool In(vector <char> vec, char target) const;

	vector<char> deadCharacters;
	bool duplicates;
	vector<char> forcedCharacters;
	vector<SmartChar> myString;

};
#endif 
