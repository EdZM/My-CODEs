#include "Decryptr.h"

Decrypter::Decrypter(bool hasDuplicates):
duplicates(hasDuplicates),
round(0) {

}

Decrypter::~Decrypter() {

}


void Decrypter::Display(vector<char> charVec) const {
    copy(charVec.begin(), charVec.end(), ostream_iterator<char>(cout," "));
}

// Iterate through history of guesses and display results
void Decrypter::ShowHistory() {
    for(vector<Guess>::const_iterator it = history.begin(); it != history.end(); it++) {
        it->Display();
    }
}
