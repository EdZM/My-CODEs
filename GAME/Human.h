#ifndef HUMAN_H
#define HUMAN_H

#include "Decryptr.h"

class Human:public Decrypter {

public:
		Human(bool duplicates);
		virtual ~Human ();

		vector<char> GetSolution() const;
		bool HandleFlag(char flag);
		bool IsValid(char c) const;
		void Play();
		void Score(vector<char> thisGuess, int &correct, int &position);

private:
		void ShowHint();
		void ShowHelp();

		int hintCtr;
		vector<char> solution;
};

#endif
