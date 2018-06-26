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
            cout << "How many letters? (";
            cout << minLetters << "-" << maxLetters << "): ";
            cin >> howManyLetters;
            if ( howManyLetters < minLetters ||
                howManyLetters > maxLetters )
            {
                cout << "please enter a number between ";
                cout << minLetters << " and ";
                cout << maxLetters << endl;
            }
        }

        // get user's preference for how many slots (positions)
        while ( howManyPositions < minPos ||
            howManyPositions > maxPos )
        {
            cout << "How many positions? (";
            cout << minPos << "-" << maxPos << "): ";
            cin >> howManyPositions;
            if ( howManyPositions < minPos ||
                howManyPositions > maxPos )
            {
                cout << "please enter a number between ";
                cout << minPos <<" and " << maxPos << endl;
            }
        }

        char choice = ' ';
        while ( choice != 'y' && choice != 'n' )
        {
            cout << "Allow duplicates (y/n)? ";
            cin >> choice;
        }

        duplicates = choice == 'y' ? true : false;

        if ( ! duplicates &&
            howManyPositions > howManyLetters )
        {
            cout << "\nI can't put " << howManyLetters;
            cout << " letters in " << howManyPositions;
            cout << " positions without duplicates! ";
            cout << "Please try again.\n\n";
            howManyLetters = 0;
            howManyPositions = 0;
            continue;
        }

        choice = ' ';
        while ( choice != 'h' && choice != 'c' )
        {
            cout << "Who guesses. (H)uman";
            cout << " or (C)omputer? (h/c)? ";
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
        cout << totalDays << " days! ";

    else if ( totalHours > 1 )
        cout << totalHours << " hours! ";

    else if ( totalMinutes > 1 )
        cout << totalMinutes << " minutes. ";

    else
        cout << totalSeconds << " seconds. ";
}

void Game::Play()
{

    int start = time( NULL );

    pDecrypter->Play();

    // report elapsed time
    int end = time( NULL );
    int totalSeconds = end - start;

    cout << "\nTotal elapsed time, this game: ";
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

        cout << "Choosing among " << totalGuesses;
        cout << " possible combinations...\n\n";

    return true;

}
