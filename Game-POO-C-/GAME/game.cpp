#include "game.h"
#include "definedvalues.h"
#include "SmartString.h"
#include "Decrypter.h"
#include "Human.h"
#include "computer.h"

#include <time.h>

int Game::howManyLetters = 0;
int Game::howManyPositions = 0;


Game::Game(Reader & rdr){
	bool isHuman;

	rdr >> isHuman;

	if ( isHuman )
		pDecrypter = new Human(rdr);
	else
		pDecrypter = new Computer(rdr);

	rdr >> duplicates;
	rdr >> howManyLetters;
	rdr >> howManyPositions;
	cout << "Jogo salvo com sucesso." << endl;

}


Game::Game(){
	while(1){
		
		// pega o numero de tipos de letras que a sequencia vai ter. Ex: se escolher 5 a sequencia só poderá ter caracteres de (a) até (e)
		while ( howManyLetters < minLetters || howManyLetters > maxLetters ){
			
			cout << "Quantas letras possiveis? (";
			cout << minLetters << "-" << maxLetters << "): ";
			cin >> howManyLetters;
			if ( howManyLetters < minLetters || howManyLetters > maxLetters ){
				cout << "Escolha um numero entre ";
				cout << minLetters << " e ";
				cout << maxLetters << endl;
			}
		}

		
		// pega o numero de posições que a sequencia vai ter
		while ( howManyPositions < minPos || howManyPositions > maxPos ){
			
			cout << "Quantas posições? (";
			cout << minPos << "-" << maxPos << "): ";
			cin >> howManyPositions;
			if ( howManyPositions < minPos || 
				howManyPositions > maxPos )
			{
				cout << "Escolha um numero entre ";
				cout << minPos <<" e " << maxPos << endl;
			}
		}

		char choice = ' ';
		while ( choice != 'y' && choice != 'n' ){ // só permite duas opções validas, sim( y ) ou nao( n )
			cout << "Permitir duplicatas (y/n)? ";
			cin >> choice;
		}

		duplicates = choice == 'y' ? true : false; 

		if ( ! duplicates && howManyPositions > howManyLetters ){
			
			cout << endl <<"Não posso colocar " << howManyLetters;
			cout << " letras em " << howManyPositions;
			cout << " posições sem duplicata! ";
			cout << "Tente de novo." << endl << endl ;
			howManyLetters = 0;
			howManyPositions = 0;
			continue;
		}

		choice = ' ';
		while ( choice != 'h' && choice != 'c' ) { //alguma opção dentre essas duas deve ser escolhida para que o jogo continue
			cout << "Quem vai adivinhar: (H)umano"; 
			cout << " ou (C)omputador? (h/c)? ";
			cin >> choice;
		}

		bool ok = choice == 'h' ?  
			true : VerifyComputerChoices();
		
		if( ok ) {
			if ( choice == 'h' )
				pDecrypter = new Human(duplicates);
			else
				pDecrypter = new Computer(duplicates);

			break;
		}
	}
}

void Game::DisplayTime(int totalSeconds){
	int totalDays = totalSeconds / SecondsInDay;
	int totalHours = totalSeconds / SecondsInHour;
	int totalMinutes = totalSeconds / SecondsInMinute;
	if ( totalDays > 1 )
		cout << totalDays << " dias! ";

	else if ( totalHours > 1 )
		cout << totalHours << " horas! ";

	else if ( totalMinutes > 1 )
		cout << totalMinutes << " minutos! ";

	else 
		cout << totalSeconds << " segundos! ";
}

void Game::Play(){

	int start = time( NULL );

	bool StoreGame = pDecrypter->Play();
	if ( StoreGame )
		Store();
		

	// fornece o tempo total de jogo 
	int end = time( NULL );
	int totalSeconds = end - start;

	cout << "\nTempo total de jogo: ";
	DisplayTime(totalSeconds);

	cout << "\n";

	howManyLetters = 0;
	howManyPositions = 0;
}


bool Game::VerifyComputerChoices(){
	int totalGuesses = 1;

	if ( duplicates )
		for ( int i = 0; i < howManyPositions; i++ )  
			totalGuesses *= howManyLetters;
	else
		for ( 
			int i = howManyLetters; 
			i > howManyLetters - howManyPositions;   
			i--
			)
			totalGuesses *= i;


	int totalSeconds = totalGuesses / GUESSES_PER_SECOND;

	if ( totalSeconds > 2 )	{
		
		cout << endl << endl <<"Voce está me pedindo para adivinhar ";
		cout << " de um total de ";
		cout << totalGuesses;
		cout <<  " combinações.";

		cout << endl <<"Consigo fazer cerca de  ";
		cout <<  GUESSES_PER_SECOND;
		cout << " tentativas por segundos. ";
		cout << "Se o desafio for dificil, com mais letras, mais tipos de letras, e com duplicatas";
		cout << endl <<"uma simples tentativa levará cerca de ";

		DisplayTime(totalSeconds);
		
		char confirm = ' ';
		while ( confirm != 'y' && confirm != 'n' ){
			cout << "\n\nTem certeza (y/n)? ";
			cin >> confirm;
		}

		if ( confirm == 'n' )
		{
			howManyLetters = 0;
			howManyPositions = 0;
			return false;
		}
	}
	else
	{
		cout << "Escolhendo entre  " << totalGuesses;
		cout << " Combinações possíveis\n\n";
	}

	return true;

}


void Game::Write(Writer & wrtr) const
{
	pDecrypter->Write(wrtr);
	wrtr << duplicates;
	wrtr << howManyLetters;
	wrtr << howManyPositions;
}


void Game::Store()
{
	char fileName[80];
	cout << "Salvo no arquivo de nome: ";
	cin >> fileName;
	cin.ignore(1,'\n');
	Writer * writer = new Writer(fileName);
	Write(*writer);
	delete writer;
}