/*
  Arquivo com a inicialização de variáveis relevantes para o jogo. Especifica quais letras são passiveis de serem escolhidas,
  intervalo de posições e como contagem do tempo será realizada

*/

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


#endif
