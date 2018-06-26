/*=================================================================================================================================

Arquivo com as funções da biblioteca DECRYPTER, 

==================================================================================================================================*/


#ifndef DECRYPTER_H
#define DECRYPTER_H

#include "definedValues.h"
#include "guess.h"
#include "storable.h"

class Reader;
class Writer;

class Decrypter  : public Storable{
public:    
	Decrypter   (bool duplicates); 
	Decrypter (Reader & rdr);
	virtual   ~Decrypter   (); 
	void   Display    (vector<char> charVec) const; 
	virtual bool HandleFlag   (char flag, bool & isStoring) = 0; 
	virtual bool Play    () = 0; 
	virtual void ShowHelp   () = 0; 
	void   ShowHistory   ();
	virtual void Write(Writer&) const = 0;

protected: 
	bool   duplicates; 
	vector<Guess> history; 
	int    round;
};

#endif 

 