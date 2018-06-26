#ifndef GUESS_H
#define GUESS_H

#include "defVals.h"
#include <utility>
using namespace std;

class Guess{
public:
    Guess(vector<char> guess, int howManyRight, int howManyInPosition);
    ~Guess() {}

    void  Display() const;
	pair<int, int>	GetScore()	const { return score; }
	vector<char>	GetString()	const { return myString; }
private:
    pair<int, int> score;
    vector<char> myString;
};

#endif
