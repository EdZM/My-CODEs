#ifndef SMARTSTRING_H
#define SMARTSTRING_H

#include "defVals.h"
#include "SmartChar.h"

class Guess;

class SmartString {

public:
    SmartString(bool dupes);
    virtual ~SmartString();

    bool CanEliminateCharacters(const Guess& theGuess);
    bool GetNext();
    vector<char> GetString();
    bool RemoveCurrentCharacters();
    bool RemoveCurrentCharactersInEveryPosition();

private:
    void ForceCharacters(const Guess& theGuess);
    int CountForcedInGuess(const Guess& theGuess);
    int CountUniqueLettersInGuess(const Guess& theGuess);
    bool In(vector<char> vec, char target) const;

    vector<char> deadCharacters;
    bool duplicates;
    vector<char> forcedCharacters;
    vector<SmartChar> myString;
};

#endif
