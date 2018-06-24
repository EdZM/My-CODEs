#include "Computer.h"
#include "smartstring.h"
#include "Game.h"
#include <string>
#include <stdlib.h>
#include <algorithm>

Computer::Computer(bool dupes):
Decrypter(dupes),
total(0),
mySmartString(0)
{
}

Computer::Computer(Reader & rdr):
Decrypter(rdr){
	mySmartString = new SmartString(rdr);
	rdr>>total;
	cout << "Computer restored.\n";

}

Computer::~Computer()
{

}

void Computer::GenerateAGuess(){

	bool ok = true;
	int counter = 0;
	int start = time( NULL );
	do
	{
		counter++;
		total++;
		if ( counter % 10000 == 0 )
			cout << ".";

		ok = mySmartString->GetNext(); 

		if ( !ok )
		{
			cout << "Something went wrong!";
			cout << " Please start over\n";
			round = 1;
			delete mySmartString;
			mySmartString = new SmartString(duplicates);
			ShowHistory();
			cout << "\n\n";
			history.clear();
			continue;
		}

	} while ( !IsConsistent(mySmartString->GetString()) );

	int end = time( NULL );
	int seconds = end - start;
	cout << "(" << counter ;
	cout << " strings eliminated this round; ";
	cout << total << " total.)";
	if ( seconds > 1 )
		cout << " [" << seconds << " seconds]";
	cout << "\n";
}

// manipular caracteres especificos digitados pelo usuario. Esses estao associados com as opções do menu
bool Computer::HandleFlag(char flag, bool & isStoring){
	bool quit = false;
	isStoring = false;
	switch (flag){
	case 's':
		ShowHistory();
		break;
	case '?':
		ShowHelp();
		break;
	case 'f':
		isStoring = true;
		quit = true;
		break;
	case 'q':
		quit = true;
		break;
	default:
		cout << endl <<"Opção desconhecida. Ignorada" << endl;
		break;
	}
	return quit;
}

bool Computer::IsConsistent(vector<char> theGuess){

	
	if ( ! duplicates){
		for (vector<char>::const_iterator it = theGuess.begin(); it != theGuess.end(); it++	){
			
			int HowMany = count(theGuess.begin(), theGuess.end(),*it);
			
			if ( HowMany > 1 )
				return false;
		}
	}

	bool isValid = true;
	
	int correct;
	int position;

	for (vector<Guess>::const_iterator it = history.begin(); it != history.end(); it++){

		vector <char> temp = it->GetString();
		
		correct = 0;
		position = 0;
		
		for ( int i = 0; i < Game::howManyLetters; i++)	{
			
			int howManyInGuess = count (theGuess.begin(), theGuess.end(), alpha[i] );
			int howManyInAnswer = count (temp.begin(), temp.end(), alpha[i]);
			correct += min(howManyInGuess, howManyInAnswer);
		
		}

		for ( int i = 0; i < Game::howManyPositions; i++){
			if ( theGuess[i] == temp[i] )
				position++;
		}

		if ( correct != it->GetScore().first || position != it->GetScore().second )	{
			isValid = false;
			break;
		}
	}

	return isValid;
}

// função para fornecer uma tentativa quando quem está jogando é o computador
Guess Computer::OfferGuess(bool & quit, bool & isStoring){
	quit = false;
	isStoring = false;
	vector<char> theGuess = mySmartString->GetString();
	
	char temp[80];
	int numCorrect, numInPosition;
	while(1){
		
		cout << "\n";
		Display(theGuess);
		cout << "Round " << round << ". ";
		cout << "Favor fornecer o numero de acertos --> \t";
		cout << "Quantas eu acertei?: ";
		cin >> temp;

		if ( temp[0] == '-' ){ 
			
			quit = HandleFlag(temp[1], isStoring);
			if ( quit ){
				numCorrect = 0;
				numInPosition = 0;
			}else
				continue;
		
		} else {
			
			numCorrect = atoi(temp);
			cout << "\t\t\tQuantas estão em posição?: ";
			cin >> numInPosition;
			round++;
		
		}
		break;
	}
	Guess thisGuess(theGuess,numCorrect,numInPosition);
	return thisGuess;
		
}

bool Computer::Play()
{

	bool quit;
	bool isStoring = false;

	if ( ! mySmartString )
		mySmartString = new SmartString(duplicates);

	vector<char> theGuess;

	bool deletedCharacters = false;

	for ( ;; )
	{
		Guess theGuess = OfferGuess(quit, isStoring);
		if ( quit )
			break;

		history.push_back(theGuess);

		if ( theGuess.GetScore().second == 
			Game::howManyPositions )
			break;

		if ( 
			! mySmartString->CanEliminateCharacters(theGuess) || 
			! IsConsistent(mySmartString->GetString()) 
			)
				GenerateAGuess();
	};
	return isStoring; 
}

// result of pressing -?
void Computer::ShowHelp()
{
	cout << "\t-s Show history\n\t-f store to File\n";
	cout << "\t-? Help\n\t-q quit\n" << endl;
}

void Computer::Write(Writer & wrtr) const
{
	wrtr << (false);  // no I'm not a human
	Decrypter::Write(wrtr);
	mySmartString->Write(wrtr);
	wrtr << total;

}

