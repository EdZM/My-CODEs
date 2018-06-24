/*=================================================================================================================================

Arquivo com as funções da biblioteca GAME, que será usada gerenciar o jogo com um todo, contando com metodos para inicializá-lo,
guardar informações do numero de letras, posições , tempo de jogo, verificação de tentativas do computador, presença/ausência de
duplicatas, entre outros.


==================================================================================================================================*/


#ifndef GAME_H
#define GAME_H

#include "definedValues.h"
#include "guess.h"
#include "SmartString.h"
#include "Storable.h"

class Guess;
class Decrypter;
class Reader;
class Writer;

class Game : Storable{
public:
	Game();
	Game(Reader& rdr);
	~Game(){}

	void Play();

	static	int howManyLetters; //ambas as variaveis nao mudarão durante o jogo todo
	static	int	howManyPositions;

	void Write (Writer & wrtr) const;

private:
	void DisplayTime(int secs);
	bool VerifyComputerChoices();
	bool duplicates;
	void Store();

	Decrypter * pDecrypter;

};

#endif