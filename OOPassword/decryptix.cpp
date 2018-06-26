#include <iostream>
#include <iterator>
#include <vector>

#include "definedValues.h"
#include "game.h"
#include "guess.h"

using namespace std;

int main()
{

	cout << "Decryptix. (c)Copyright 1999";
	cout << "Liberty Associates, Inc.";
	cout << "Version 4.0\n\n" << endl;
	cout << "There are two ways to play Decryptix:";
	cout << "either you can guess a pattern I create,\n";
	cout << "or I can guess your pattern.\n\n";
	cout << "If you are guessing, I will think of a ";
	cout << "pattern of letters (e.g., abcde).\n";
	cout << "On each turn, you guess the pattern and ";
	cout << "I will tell you how many letters you \n";
	cout << "got right, and how many of the correct ";
	cout << "letters were in the correct position.\n\n";
	cout << "The goal is to decode the puzzle as quickly ";
	cout << "as possible. You control how many\n";
	cout << "letters can be used and how many positions ";
	cout << "(e.g., 5 possible letters in 4\n";
	cout << "positions) as well as whether or not the ";
	cout << "pattern might contain duplicate \n";
	cout << "letters (e.g., aabcd).\n\n";
	cout << "If I'm guessing, you think of a pattern ";
	cout << "and score each of my answers.\n\n";
	bool playAgain = true;

	while ( playAgain )
	{
		Game * g; // criando o jogo 

		char resume = ' ';
		while ( resume != 'R' && resume != 'N' )
		{
			cout << "Resume existing game or start new?. (R)esume";
			cout << " or (N)ew? ";
			cin >> resume;
		}

		if ( resume == 'R' )
		{
			char fileName[80];
			cout << "Resume from file named: ";
			cin >> fileName;
			cin.ignore(1,'\n');

			Reader * reader = new Reader(fileName);
			g = new Game(*reader);
			delete reader;
		}
		else
			g = new Game; //alocando espaço para o novo jogo 


		g->Play();

		delete g;

		char choice = ' ';
		while ( choice != 'y' && choice != 'n' ){
			cout << "\nDeseja jogar novamente? (y/n): ";
			cin >> choice;
		}

		playAgain = choice == 'y' ? true : false;		
	}
		
	return 0;
}

