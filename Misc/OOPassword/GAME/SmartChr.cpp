/*
    Implementação da classe SmartChar, responsável por
    verificar a validade da tentativa gerada pelo computador
    quando ele estiver jogando, caractere a caractere
*/

#include "SmartChar.h"
#include "Game.h"

SmartChar::SmartChar(int letter):
myChar(letter) {
    for (int i = 0; i < Game::howManyLetters; i++)
        myCharacters.push_back(alpha[i]);
}

SmartChar::~SmartChar() {
}

char SmartChar::GetChar() const {
    return myCharacters[myChar];
}

bool SmartChar::Increment() {
    if ( ++myChar >= myCharacters.size() )  {
        myChar = 0;
        return true;
    }
    return false;
}

char SmartChar::RemoveCurrent() {
    char theChar = ' ';

    if ( myCharacters.size() > 1 ) {
        theChar = GetChar();
        myCharacters.erase( myCharacters.begin()+myChar );
        while ( myChar >= myCharacters.size() )
            myChar--;
    }
    return theChar;
}

bool SmartChar::Remove(char theChar) {
    if ( myCharacters.size() > 1 ){
        vector<char>::iterator where = find(myCharacters.begin(), myCharacters.end(),theChar);
        if ( where != myCharacters.end() )
            myCharacters.erase(where);
        return true;
    }
    return false;
}
