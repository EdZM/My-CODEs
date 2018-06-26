#include "Human.h"
#include "Game.h"
#include <string>
#include <algorithm>

Human::Human(bool dupes):
Decrypter(dupes),
hintCtr(0)
{

}

Human::~Human()
{

}

vector<char> Human::GetSolution() const
{
    return solution;
}

// Handle any flag from user (-?,-q, etc.)
bool Human::HandleFlag(char flag)
{
    bool quit = false;
    switch (flag)
    {
    case 'h':
        ShowHint();
        break;
    case 's':
        ShowHistory();
        break;
    case '?':
        ShowHelp();
        break;
    case '!':
        Display(GetSolution());
        break;
    case 'q':
        quit = true;
        break;
    default:
        cout << endl << "Comando desconhecido. Ignorado." << endl;
        break;
    }
    return quit;
}

bool Human::IsValid(char theChar) const
{
    bool isValid = false;

    for ( int i = 0; i < Game::howManyLetters; i++ )
        if ( alpha[i] == theChar )
            isValid = true;

    return isValid;
}

void Human::Play()
{
    vector<char> thisGuess;
    int correct = 0;
    int position = 0;
    bool quit = false;
    round++;

    srand( (unsigned)time( NULL ) );

    for ( int i = 0; i <
        Game::howManyPositions; )
    {
        int nextValue = rand() % (Game::howManyLetters);
        char theChar = alpha[nextValue];
        if ( ! duplicates && i > 0 )
        {
            vector<char>::iterator where =
                find(solution.begin(), solution.end(),theChar);
            if ( where != solution.end() )
                continue;
        }
        solution.push_back(theChar);
        i++;
    }

    while ( position < Game::howManyPositions )
    {
        thisGuess.clear();
        string guess;

        cout << "\nRound " << round;
        cout << ". Digite -? ou ";
        cout << Game::howManyPositions;
        cout << " letras entre ";
        cout << alpha[0] << " e ";
        cout << alpha[Game::howManyLetters-1] << ": ";

        cin >> guess;

        if ( guess[0] == '-' )// got a flag
        {
            quit = HandleFlag(guess[1]);
            if ( quit )
                break;
            continue;
        }

        if ( guess.length() < Game::howManyPositions )
        {
            cout << endl << "** Por favor, digite entre exatamente ";
            cout << Game::howManyPositions << " letras. **" << endl;
            continue;
        }

        bool lineIsValid = true;

        // ensure they've entered only possible letters
        for ( int i = 0; i < Game::howManyPositions; i++)
        {
            lineIsValid = IsValid(guess[i]);
            if ( ! lineIsValid )
                break;
        }

        // create the guess for display
        if ( lineIsValid )
            for (
                int i = 0;
                i < Game::howManyPositions;
                i++
                )
                thisGuess.push_back(guess[i]);
        else
        {

            cout << "Por favor, digite apenas letras entre ";
            cout << alpha[0] << " e ";
            cout << alpha[Game::howManyLetters-1] << endl;
            continue;
        }

        round++;
        cout << endl << "Sua tentativa: ";
        Display(thisGuess);

        // compute and report how they did
        Score(thisGuess,correct,position);
        cout << "\t\t" << correct << " corretas, ";
        cout << position << " em posicao." << endl;

        // crate a record and record it in the history vector
        Guess thisRound(thisGuess,correct,position);
        history.push_back(thisRound);
    }

    if ( ! quit )
    {
        cout << endl << "A resposta: ";
        Display(GetSolution());
        cout << "\n\n" << endl;

        cout << endl<< "\nParabéns!!! Levou ";

        if ( round <= 6 )
            cout << "apenas ";

        if ( round-1 == 1 )
            cout << "um round!" << endl;
        else
            cout << round-1 << " rounds." << endl;
    }
}


// human guessing, see how many letters & position match
void Human::Score(
                  vector<char> thisGuess,
                  int & correct,
                  int & position
                  )
{
    correct = 0;
    position = 0;
    int i;

    // for every possible letter,
    // how many are in each the answer and the guess
    for ( i = 0; i < Game::howManyLetters; i++)
    {
        int howManyInGuess = count(
                            thisGuess.begin(),
                            thisGuess.end(),
                            alpha[i]
                            );
        int howManyInAnswer = count(
                                    solution.begin(),
                                    solution.end(),
                                    alpha[i]
                                    );
        correct += min(howManyInGuess, howManyInAnswer);
    }

    // for each position in the guess
    // how many match the solution
    for (  i = 0; i < Game::howManyPositions; i++)
    {
        if ( thisGuess[i] == solution[i] )
            position++;
    }
}

// When human is guessing, reveal each letter one by one
void Human::ShowHint()
{
    if ( hintCtr < Game::howManyPositions ) {
        cout << "\nDICA!! Posicao ";
        cout << hintCtr+1 << ": ";
        cout << solution[hintCtr] << endl;
        hintCtr++;
    }
}
    // result of pressing -?
void Human::ShowHelp()
{
    cout << "\t-h Dica\n\t-s Mostrar historico\n\t";
    cout << "-? Ajuda\n\t-q Sair\n" << endl;
}
