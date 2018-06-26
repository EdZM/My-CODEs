#ifndef SMARTCHAR_H
#define SMARTCHAR_H

#include "defVals.h"

class SmartChar {

public:
    SmartChar(int letter = 0);
    virtual ~SmartChar();

    char GetChar() const;
    bool Increment();
    char RemoveCurrent();
    bool Remove(char c);

private:
    int myChar;
    vector<char> myCharacters;
};

#endif
