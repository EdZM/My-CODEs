#include <iostream>
#include <iterator>
#include <vector>

#include "defVals.h"
#include "Game.h"
#include "Guess.h"

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
		char choice = ' ';
		Game * g = new Game;
		g->Play();

		delete g;

		while ( choice != 'y' && choice != 'n' )
		{
			cout << "\nPlay again (y/n): ";
			cin >> choice;
		}

		playAgain = choice == 'y' ? true : false;
	}

	return 0;
}
