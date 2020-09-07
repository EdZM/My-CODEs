/*
    classe abstrata Decryptr, responsável por manusear as
    tentativas feitas por qualquer jogador, seja ele humano ou
    computador.
*/

#include "Decryptr.h"

Decrypter::Decrypter(bool hasDuplicates):
duplicates(hasDuplicates), // inicializando variaveis
round(0) {

}

Decrypter::~Decrypter() {

}


void Decrypter::Display(vector<char> charVec) const {
    copy(charVec.begin(), charVec.end(), ostream_iterator<char>(cout," "));
}

// Iterar no historico de tentativas e mostrar os resultados
void Decrypter::ShowHistory() {
    for(vector<Guess>::const_iterator it = history.begin(); it != history.end(); it++) {
        it->Display();
    }
}
