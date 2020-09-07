#!/bin/sh

# para executar cole esse arquivo na pasta onde quer renomear os arquivos de um dado formato
# Depois digite no terminal: ./Rename.sh "<nome_a_ser_retirado>" "<nome_a_ser_incluido>" "formato_dos_arquivos"

OLDEST=$1 # recebe o primeiro argumento(nome_a_ser_retirado) apos o ./Rename.sh 
NEWEST=$2 # recebe o segundo argumento(nome_a_ser_incluido) apos o ./Rename.sh 
EXTENSION=$3 # recebe o terceiro argumento(formato_dos_arquivos) apos o ./Rename.sh 


for FILE in *$EXTENSION ; #percorre cada arquivo com o formato especificado
do 

#echo $FILE --> imprime o nome de cada arquivo que tem o formato desejado
NEWFILE=`echo $FILE | sed 's/'$OLDEST'/'$NEWEST'/g'` ; #NEWFILE tem as alterações que desejo. Retira tudo o que tiver nome "<nome_a_ser_retirado>" e troca por <nome_a_ser_incluido>
mv -v "$FILE" $NEWFILE ; # muda o nome de FILE "$FILE" para $NEWFILE OBS.: -v" == verbose output. Print the name of every file moved
#echo "$FILE será renomeado como $NEWFILE" ; 

done