#ifndef GAME_H
#define GAME_H

#include "defVals.h"
#include "guess.h"
#include "SmartStr.h"

class Guess;
class Decrypter;

class Game
{
public:
	Game();
	~Game(){}

	void Play();

	static int howManyLetters;
	static int howManyPositions;

private:
	void    DisplayTime(int secs);
	bool    VerifyComputerChoices();
	bool    duplicates;

	Decrypter *        pDecrypter;

};

#endif
