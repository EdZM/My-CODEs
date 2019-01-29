#!/bin/sh

for FILE in *.<formato_do_arquivo> ; #percorre cada arquivo com o formato especificado
do 

#echo $FILE --> imprime o nome de cada arquivo que tem o formato .mkv
NEWFILE=`echo $FILE | sed 's/<nome_a_ser_retirado>/<nome_a_ser_incluido>/g'` ; #NEWFILE tem as alterações que desejo. Retira tudo o que tiver nome "<nome_a_ser_retirado>" e troca por <nome_a_ser_incluido>
mv -v "$FILE" $NEWFILE ; # muda o nome de FILE "$FILE" para $NEWFILE OBS.: -v" == verbose output. Print the name of every file moved
#echo "$FILE será renomeado como $NEWFILE" ; 

done