#include "guess.h"


Guess::Guess(vector<char>guess, int howManyRight, int howManyInPosition):
string(guess),
score(howManyRight, howManyInPosition)
{
}

Guess::Guess(Reader & rdr){
	rdr >> score.first;
	rdr >> score.second;
	int len;
	rdr >> len;
	char theChar;
	for ( int i = 0; i < len; i++ )	{
		rdr >> theChar;
		string.push_back(theChar);
	}


}

void Guess::Display() const{
	copy(
		string.begin(), 
		string.end(),
		ostream_iterator<char>(cout," ")
		);
	cout << "\t" << score.first;
	cout << " corretas, " << score.second;
	cout << " em posição\n";
}

pair<int, int> Guess::GetScore()const{ 
	return score; 
}

vector<char> Guess::GetString()	const{ 
	return string; 
}

void Guess::Write(Writer & wrtr) const{

	wrtr << score.first;
	wrtr << score.second;
	int len = string.size();
	wrtr << len;

	for (vector<char>::const_iterator it = 	string.begin(); it != string.end(); it++ ) {
		char theChar = it[0];
		wrtr <<  theChar;
	}
}
