#include "Human.h"
#include "Game.h"
#include <string>
#include <algorithm>

Human::Human(bool dupes):
Decrypter(dupes),
hintCtr(0)
{
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

}

Human::Human(Reader & rdr):
Decrypter(rdr)
{
	rdr >> hintCtr;
	rdr >> solution;
	cout << "Solution and history restored.\n";

}


Human::~Human()
{

}

vector<char> Human::GetSolution() const		
{ 
	return solution; 
}

// manipular caracteres especificos digitados pelo usuario. Esses estao associados com as opções do menu
bool Human::HandleFlag(char flag, bool & storeGame){
	bool quit = false;
	switch (flag){
	
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
	case 'f':
		storeGame = true;
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

bool Human::IsValid(char theChar) const
{
	bool isValid = false;

	for ( int i = 0; i < Game::howManyLetters; i++ )
		if ( alpha[i] == theChar )
			isValid = true;

	return isValid;
}

bool Human::Play(){
	vector<char> thisGuess;
	int correct = 0;
	int position = 0;
	bool quit = false;
	bool storeGame = false;


	while ( position < Game::howManyPositions )	{
		thisGuess.clear();
		string guess;

		cout << endl <<"Round " << round;
		cout << ". Digite -? ou ";
		cout << Game::howManyPositions;
		cout << " Letras entre ";
		cout << alpha[0] << " e ";
		cout << alpha[Game::howManyLetters-1] << ": ";
	
		cin >> guess;

		if ( guess[0] == '-' ){
			quit = HandleFlag(guess[1], storeGame);
			if ( quit )
				break;
			else
				continue;
		}

		if ( guess.length() < Game::howManyPositions ){
			cout << "\n ** Por favor insira EXATAMENTE ";
			cout << Game::howManyPositions << " letras. **\n";
			continue;
		}

		bool lineIsValid = true;

		// ensure they've entered only possible letters
		// garantindo que o que foi digitado foram APENAS letras
		for ( int i = 0; i < Game::howManyPositions; i++){
			
			lineIsValid = IsValid(guess[i]);
			if ( ! lineIsValid )
				break;
		}

		// criando uma tentativa a partir da sequencia digitada pelo usuario
		if ( lineIsValid )
			for ( int i = 0; i < Game::howManyPositions; i++ )
				thisGuess.push_back(guess[i]);
		else{

			cout << "Favor inserir APENAS letras entre ";
			cout << alpha[0] << " e ";
			cout << alpha[Game::howManyLetters-1] << endl;
			continue;
		}

		round++;
		cout << endl << "Sua tentativa: ";
		Display(thisGuess);

		// armazenar e dizer como o jogador se saiu em sua tentativa
		Score(thisGuess,correct,position);
		cout << "\t\t" << correct << " corretas, ";
		cout << position << " em posição." << endl;

		// salvando a ultima tentativa em um historico de tentativas
		Guess thisRound(thisGuess,correct,position);
		history.push_back(thisRound);
	}

	// mostrar o resultado do jogo 
	if ( ! quit ){
		cout << endl <<"Resposta : ";
		Display(GetSolution());
		cout << endl << endl << endl;

		cout << endl << endl << "Parabéns, Fim de jogo! Foi necessário ";

		if ( round <= 6 )
			cout << "apenas ";

		if ( round-1 == 1 )
			cout << "um round!" << endl;
		else
			cout << round-1 << " rounds." << endl;
	}
	return storeGame;

}


// função para quantificar os acertos da tentativa do jogador humano
void Human::Score( vector<char> thisGuess, int & correct, int & position ){
	correct = 0;
	position = 0;

	// para cada letra possivel
	// quantas delas estao na resposta e na tentativa
	for ( int i = 0; i < Game::howManyLetters; i++)	{
		
		int howManyInGuess = count(	thisGuess.begin(), thisGuess.end(), alpha[i] );
		int howManyInAnswer = count( solution.begin(), solution.end(), alpha[i]	);
		correct += min(howManyInGuess, howManyInAnswer); // só quantifica os acertos
	
	}

	// De cada posição na tentativa
	// quantas batem com as posições da resposta
	for (int  i = 0; i < Game::howManyPositions; i++)
	{
		if ( thisGuess[i] == solution[i] )
			position++;
	}
}


// função para mostrar uma DICA ao jogador. A cada chamada dessa função uma posição sequencial da resposta é revelada
void Human::ShowHint() {
	if ( hintCtr < Game::howManyPositions )	{
		cout << endl <<"DICA!! Posição ";
		cout << hintCtr+1 << ": ";
		cout << solution[hintCtr] << endl;
		hintCtr++; //controle de dica, para que na proxima chamada seja revelada a posição seguinte da resposta
	}
}
// função para mostrar o resultado de apertar "-?"
void Human::ShowHelp(){
	cout << "\t-h Dica\n\t-s Mostrar historico de tentativas\n\t";
	cout << "-? Ajuda\n";
	cout << "\t-f store to File\n\t-q sair\n" << endl;
}

void Human::Write(Writer & wrtr) const{
	wrtr << (true);  // sim, sou humano! --> indica qual jogador esta jogando
	Decrypter::Write(wrtr);
	wrtr << hintCtr;
	wrtr << solution;

}

