#include "SmartString.h"
#include "Game.h"
#include "Guess.h"

SmartString::SmartString(bool dupes) : duplicates(dupes){
	for ( int i = 0; i < Game::howManyPositions; i++ )	{
		int j;
		if ( duplicates )
			j = 0;
		else
			j = i;
		SmartChar theChar(j);
		myString.push_back(theChar);
	}
}

SmartString::SmartString(Reader & rdr){
	rdr >> deadCharacters;
	rdr >> duplicates;
	rdr >> forcedCharacters;
	int size;
	rdr >> size;
	for ( int i = 0; i < size; i++)	{
		SmartChar theSmartChar(rdr);
		myString.push_back(theSmartChar);
	}
}

SmartString::~SmartString(){

}

vector<char> SmartString::GetString(){
	vector<char> outString;
	
	for ( vector<SmartChar>::iterator it = myString.begin(); it != myString.end(); it++	){
		
		char theChar = it->GetChar();
		outString.push_back(theChar);
	
	}
	return outString;
}


bool SmartString::GetNext(){
	vector<char> outString;
	vector<SmartChar>::reverse_iterator it;
	it = myString.rbegin(); 
	
	bool rollover = it->Increment();
	while ( rollover ){
		it++;
		
		if ( it == myString.rend() )
			return false;
		
		else {
			rollover = it->Increment();
		}
	}
	return true;
}



//remove um caracter que está sendo mostrado, em uma posição específica
bool SmartString::RemoveCurrentCharacters(){
	char theChar;
	bool anyDeleted = false;

	for (vector<SmartChar>::iterator it = myString.begin(); it != myString.end(); it++ ){
		theChar = it->GetChar();

		if ( ! In(forcedCharacters,theChar) ){
			theChar = it->RemoveCurrent();
			// dead characters stop you from 
			// reporting removal of characters already dead
			if (! In(deadCharacters,theChar) )	{
				
				deadCharacters.push_back(theChar);
				cout << "Eliminando " << theChar;
				cout << " da posição atual" << endl;
				anyDeleted = true;
			
			}
		}
	}
	return anyDeleted;
}


// removes character that is currently shown
// in a particular position from every position
bool SmartString::RemoveCurrentCharactersInEveryPosition(){
	char theChar;
	bool anyDeleted = false;
	vector <char> currentGuess;

	for (
		vector<SmartChar>::iterator it = myString.begin(); 
		it != myString.end(); 
		it++
		)
	{
		currentGuess.push_back(it->GetChar());
	}

	for (
		vector<char>::iterator itc = currentGuess.begin(); 
		itc != currentGuess.end(); 
		itc++
		)
	{
		theChar = *itc;
		if ( ! In(forcedCharacters,theChar) )
		{
			
			for (
				vector<SmartChar>::iterator it2 = myString.begin(); 
				it2 != myString.end(); 
				it2++
				)
			{
				it2->Remove(theChar);
				if (! In(deadCharacters,theChar) )  
				{
					deadCharacters.push_back(theChar);
					cout << "Eliminating " << theChar << endl;
					anyDeleted = true;
				}
			}
		}
	}
	return anyDeleted;
}

bool SmartString::CanEliminateCharacters(const Guess & theGuess)
{

	bool anyDeleted = false;
	ForceCharacters(theGuess);
	int forcedInAnswer = CountForcedInGuess(theGuess);

	int overall = theGuess.GetScore().first;
	int inPos = theGuess.GetScore().second;


	if ( overall == 0 || overall == forcedInAnswer )
	{
		anyDeleted = RemoveCurrentCharactersInEveryPosition();
		return anyDeleted; // we did eliminate characters
	}

	if ( inPos == 0 ) 
	{
		anyDeleted = RemoveCurrentCharacters();
		return anyDeleted; // we did eliminate characters
	}

	return false;
}

void SmartString::ForceCharacters(const Guess &theGuess)
{
	int numDifferentLetters = 
		CountUniqueLettersInGuess(theGuess);
	int score = theGuess.GetScore().first;

	if ( score >= numDifferentLetters )
	{
		vector<char> theString = 
			theGuess.GetString();

		for (
			vector<char>::const_iterator it = theString.begin(); 
			it != theString.end(); 
			it++
			)
		{
			if ( ! In(forcedCharacters, *it) )
				forcedCharacters.push_back(*it);
		}
	}
}

int SmartString::CountUniqueLettersInGuess(const Guess &theGuess)
{
	vector<char> temp;
	vector<char> theString = 
		theGuess.GetString();

	for (
		vector<char>::const_iterator it = theString.begin(); 
		it != theString.end(); 
		it++
		)
	{
		if (! In(temp,*it) )
			temp.push_back(*it);
	}

	// temp now has all the unique letters

	return temp.size();
}

int SmartString::CountForcedInGuess(const Guess &theGuess)
{
	int howManyForcedInGuess = 0;
	vector<char> theString = theGuess.GetString();

	for (
		vector<char>::const_iterator it = theString.begin(); 
		it != theString.end(); 
		it++
		)
	{
		if ( In( forcedCharacters, *it ) )
			howManyForcedInGuess++;
	}

	return howManyForcedInGuess;

}

bool SmartString::In(vector<char> vec, char target) const
{
	vector<char>::iterator where = 
		find(vec.begin(), vec.end(),target);
	return where != vec.end();
}

void SmartString::Write(Writer & wrtr) const
{
	wrtr << deadCharacters;
	wrtr << duplicates;
	wrtr << forcedCharacters;
	int len = myString.size();
	wrtr << len;
	for (
		vector<SmartChar>::const_iterator it = 
			myString.begin(); 
		it != myString.end(); 
		it++
		)
	{
		it->Write(wrtr);
	}

}
