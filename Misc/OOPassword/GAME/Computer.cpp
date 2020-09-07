/*
    Implementação da classe Computer,
    responsável por gerenciar o jogo do computador,
    verificando seus acertos, contabilizando o tempo decorrido e
    processando e analisando suas tentativas.
*/


#include "Computer.h"
#include "SmartStr.h"
#include "Game.h"
#include <algorithm>

Computer::Computer(bool dupes):
Decrypter(dupes),
total(0),
mySmartString(0) {

}

Computer::~Computer() {

}

void Computer::GenerateAGuess() {

    bool ok = true;
    int start = time( NULL );

    do {
        total++;

        ok = mySmartString->GetNext();

        if (!ok) {

            cout << "Alguma coisa deu errado!";
            cout << " Por favor, comece novamente." << endl;
            round = 0;
            delete mySmartString;
            mySmartString = new SmartString(duplicates);
            ShowHistory();
            cout << endl;
            history.clear();
            continue;
        }

    } while(!IsConsistent(mySmartString->GetString()));

    int end = time( NULL );
    int seconds = end - start;
    if(seconds > 1 )
        cout << " [" << seconds << " segundos]";
    cout << endl;
}

// Administrando a flag (-?,-q, etc.)
bool Computer::HandleFlag(char flag) {
    bool quit = false;
    switch (flag) {

        case 's':
            ShowHistory();
            break;

        case '?':
            ShowHelp();
            break;

        case 'q':
            quit = true;
            break;

        default:
            cout << "\nComando desconhecido. Ignorado." << endl;
            break;

    }
    return quit;
}

bool Computer::IsConsistent(vector<char> theGuess) {


    if(!duplicates) {
        for(vector<char>::const_iterator it = theGuess.begin(); it != theGuess.end(); it++) {
            int HowMany = count(theGuess.begin(), theGuess.end(), *it);
            if(HowMany > 1)
                return false;
        }
    }

    bool isValid = true;

    int correct;
    int position;

    for(vector<Guess>::const_iterator it = history.begin(); it != history.end(); it++) {

        vector <char> temp = it->GetString();

        correct = 0;
        position = 0;

        for(int i = 0; i < Game::howManyLetters; i++) {
            int howManyInGuess = count (theGuess.begin(), theGuess.end(), alpha[i]);
            int howManyInAnswer = count (temp.begin(), temp.end(), alpha[i]);
            correct += min(howManyInGuess, howManyInAnswer);
        }

        for(int i = 0; i < Game::howManyPositions; i++) {
            if(theGuess[i] == temp[i])
                position++;
        }

        if(correct != it->GetScore().first || position != it->GetScore().second) {
            isValid = false;
            break;
        }
    }

    return isValid;
}

Guess Computer::OfferGuess() {

    vector<char> theGuess = mySmartString->GetString();
    round++;

    int numCorrect, numInPosition;
    cout << endl;
    Display(theGuess);
    cout << "Round " << round << ". ";
    cout << "Por favor, digite minha pontuacao." << endl;
    cout << "Quantas corretas?: ";
    cin >> numCorrect;
    cout << "\t\t\tQuantas na posicao?: ";
    cin >> numInPosition;
    Guess thisGuess(theGuess, numCorrect, numInPosition);

    return thisGuess;
}

void Computer::Play() {

    if(!mySmartString)
        mySmartString = new SmartString(duplicates);

    vector<char> theGuess;
    history.clear();

    bool deletedCharacters = false;

    while(1) {
        Guess theGuess = OfferGuess();
        history.push_back(theGuess);

        if(theGuess.GetScore().second == Game::howManyPositions)
            break;

        if (!mySmartString->CanEliminateCharacters(theGuess) || !IsConsistent(mySmartString->GetString()))
            GenerateAGuess();
    }
}

// Administrar menu de opções -?
void Computer::ShowHelp()
{
    cout << "\t-s Mostrar histórico\n\t-? Ajuda\n";
    cout << "\t-q Sair\n" << endl;
}
