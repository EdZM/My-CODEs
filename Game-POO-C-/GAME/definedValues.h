/*=================================================================================================================================

Arquivo com as funções da biblioteca Definedvalues, que atribui alguns dos valores mais relevantes para o jogo rodar corretamente,
como vetor com os caracteres alphanumericos, numero max/min de letras, tentativas por segundo, etc.


==================================================================================================================================*/


#ifndef DEFINED
#define DEFINED

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <time.h>
#include <utility>

using namespace std;

const char alpha[27] = "abcdefghijklmnopqrstuvwxyz";

const int minPos = 2;
const int maxPos = 10;
const int minLetters = 2;
const int maxLetters = 26;
const int SecondsInMinute = 60;
const int SecondsInHour = SecondsInMinute * 60;
const int SecondsInDay = SecondsInHour * 24;
const int GUESSES_PER_SECOND = 10000;

const int szInt =  sizeof(int);
const int szChar = sizeof(char);
const int szBool = sizeof(bool);

#endif