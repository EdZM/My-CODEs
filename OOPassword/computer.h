/*=================================================================================================================================

Arquivo com as funções da biblioteca COMPUTER, que é responsável por gerenciar todo o jogo do computador, quando for ele quem estiver
jogando. Tem metodos importantes como os que criam tentativas, verificação de consistencia de tentativa, exibição de tentativa, etc.

==================================================================================================================================*/

#ifndef COMPUTER_H
#define COMPUTER_H

#include "Decrypter.h"

class SmartString;
class Reader;
class Writer;

class Computer  : public Decrypter {
public:
	Computer (bool duplicates);
	Computer (Reader & rdr);
	virtual ~Computer();
	bool HandleFlag(char flag, bool & isStoring);
	bool Play();
	virtual void Write(Writer& wrtr) const;

private:
	void GenerateAGuess ();
	bool IsConsistent (vector<char> guess);
	Guess OfferGuess(bool & quit, bool & isStoring);

	void ShowHelp();
	SmartString * mySmartString;
	int	total;
};

#endif 
