/*=================================================================================================================================

Arquivo com as funções da biblioteca STORABLE, que salva/resume o contexto do jogo. Tem principalmente metodos virtuais com sobrecarga de 
operadores de iostream  , que podem escrever em um arquivo, o que gerará um SAVEGAME ou ler um SAVEGAME  já existente

==================================================================================================================================*/


#ifndef STORABLE_H
#define STORABLE_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Reader;
class Writer;
class Guess;

class Storable {
public:
	Storable(){}
	Storable(Reader&) {}
	virtual ~Storable(){}
	virtual void Write(Writer&) const = 0;
};

class Reader{
public:
	Reader(char * filename):fin(filename,ios::binary){}
	virtual ~Reader(){fin.close();}
	virtual Reader& operator >> (int&);
	virtual Reader& operator >> (const int&);
	virtual Reader& operator >> (char&);
	virtual Reader& operator >> (char*&);
	virtual Reader& operator >> (bool&);
	virtual Reader& operator >> (vector<char>&);

private:
	ifstream fin;
};

class Writer{
public:
	Writer(char * filename):fout(filename, ios::binary){};
	virtual ~Writer() {fout.close(); }
	virtual Writer& operator << (int &);
	virtual Writer& operator << (const int &);
	virtual Writer& operator << (char&);
	virtual Writer& operator << (char*&);
	virtual Writer& operator << (const char*&);
	virtual Writer& operator << (bool&);
	virtual Writer& operator << (const bool&);
	virtual Writer& operator << (const vector<char>&);

private:
	ofstream fout;
};

#endif 