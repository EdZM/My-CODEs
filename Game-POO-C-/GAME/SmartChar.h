
/*=================================================================================================================================

Arquivo com as funções da biblioteca SMARTCHAR, usada com objetivo semelhante a SMARTSTRING, que é o de gerenciar o jogo do compu-
tador


==================================================================================================================================*/


#ifndef SMARTCHAR_H
#define SMARTCHAR_H

#include "definedValues.h"
#include "Storable.h"

class SmartChar : public Storable{
public:
	SmartChar(int letter = 0);
	SmartChar(Reader& rdr);
	virtual ~SmartChar();

	char GetChar()	const;
	bool Increment();
	char RemoveCurrent();
	bool Remove(char c);
	void Write(Writer& wrtr) const;

private:
	int				myChar;
	vector<char>	myCharacters;

};

#endif 
