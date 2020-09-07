#ifndef DECRYPTER_H
#define DECRYPTER_H

#include "defVals.h"
#include "Guess.h"

class Decrypter {

public:
		Decrypter(bool duplicates);
		virtual	~Decrypter();
		void Display(vector<char> charVec) const;
		virtual bool HandleFlag(char flag) = 0;
		virtual void Play() = 0;
		virtual void ShowHelp() = 0;
		void ShowHistory();

protected:
		bool duplicates;
		vector<Guess> history;
		int round;
};

#endif
