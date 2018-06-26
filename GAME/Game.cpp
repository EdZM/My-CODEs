#include "Game.h"
#include "defVals.h"
#include "SmartStr.h"
#include "Decryptr.h"
#include "Human.h"
#include "Computer.h"

#include <time.h>

int Game::howManyLetters = 0;
int Game::howManyPositions = 0;

Game::Game()
{
    for ( ;; )
    {
        // get user's preference for how many possible letters
        while ( howManyLetters < minLetters ||
            howManyLetters > maxLetters )
        {
            cout << "Quantas letras? (";
            cout << minLetters << "-" << maxLetters << "): ";
            cin >> howManyLetters;
            if ( howManyLetters < minLetters ||
                howManyLetters > maxLetters )
            {
                cout << "Por favor, insira um numero entre ";
                cout << minLetters << " e ";
                cout << maxLetters << endl;
            }
        }

        // get user's preference for how many slots (positions)
        while ( howManyPositions < minPos ||
            howManyPositions > maxPos )
        {
            cout << "Quantas posicoes? (";
            cout << minPos << "-" << maxPos << "): ";
            cin >> howManyPositions;
            if ( howManyPositions < minPos ||
                howManyPositions > maxPos )
            {
                cout << "Por favor, insira um numero entre ";
                cout << minPos <<" e " << maxPos << endl;
            }
        }

        char choice = ' ';
        while ( choice != 's' && choice != 'n' )
        {
            cout << "Permitir duplicatas (s/n)? ";
            cin >> choice;
        }

        duplicates = choice == 's' ? true : false;

        if ( ! duplicates &&
            howManyPositions > howManyLetters )
        {
            cout << "\nNao posso colocar " << howManyLetters;
            cout << " letras em " << howManyPositions;
            cout << " posicoes sem duplicatas! ";
            cout << "Por favor, tente novamente.\n" << endl;
            howManyLetters = 0;
            howManyPositions = 0;
            continue;
        }

        choice = ' ';
        while ( choice != 'h' && choice != 'c' )
        {
            cout << "Quem sera desafiado? (H)umano";
            cout << " ou (C)omputador? (h/c)? ";
            cin >> choice;
        }

        bool ok = choice == 'h' ?
            true : VerifyComputerChoices();
        if( ok )
        {
            if ( choice == 'h' )
                pDecrypter = new Human(duplicates);
            else
                pDecrypter = new Computer(duplicates);

            break;
        }
    }
}

void Game::DisplayTime(int totalSeconds)
{
    int totalDays = totalSeconds / SecondsInDay;
    int totalHours = totalSeconds / SecondsInHour;
    int totalMinutes = totalSeconds / SecondsInMinute;
    if ( totalDays > 1 )
        cout << totalDays << " dias! ";

    else if ( totalHours > 1 )
        cout << totalHours << " horas! ";

    else if ( totalMinutes > 1 )
        cout << totalMinutes << " minutos. ";

    else
        cout << totalSeconds << " segundos. ";
}

void Game::Play()
{

    int start = time( NULL );

    pDecrypter->Play();

    // report elapsed time
    int end = time( NULL );
    int totalSeconds = end - start;

    cout << "\nTempo total de jogo: ";
    DisplayTime(totalSeconds);

    cout << "\n";

    howManyLetters = 0;
    howManyPositions = 0;
}


bool Game::VerifyComputerChoices()
{
    int totalGuesses = 1;

    if ( duplicates )
        for ( int i = 0; i < howManyPositions; i++ )
            totalGuesses *= howManyLetters;
    else
        for (int i = howManyLetters; i > howManyLetters - howManyPositions; i--)
            totalGuesses *= i;

        cout << "Escolhendo entre " << totalGuesses;
        cout << " possiveis combinacoes...\n" << endl;

    return true;

}
