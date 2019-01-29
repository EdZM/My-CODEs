#ifndef COMPUTER_H
#define COMPUTER_H

#include "Decryptr.h"

class SmartString;

class Computer:public Decrypter {

public:
    Computer(bool duplicates);
    virtual ~Computer();
    bool HandleFlag(char flag);
    void Play();

private:
    void GenerateAGuess();
    bool IsConsistent(vector<char> guess);
    Guess OfferGuess();
    void ShowHelp();

    SmartString *mySmartString;
    int total;
};

#endif
