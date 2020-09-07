#!/bin/sh

#para usar o script com as outras buscas troque o valor de OP e altere o nome do arquivo metricasDFS.txt

cd ../src/

g++ ../calculo_metricas/metricas.cpp -o ../calculo_metricas/metricas

echo "Labirinto 5x5\n" > ../calculo_metricas/metricas_BFS.txt
make -s run_test TEST_FILE=../mazes/maze5_5-1.txt OP=2 > ../calculo_metricas/saida1.txt
make -s run_test TEST_FILE=../mazes/maze5_5-2.txt OP=2 >> ../calculo_metricas/saida1.txt
make -s run_test TEST_FILE=../mazes/maze5_5-3.txt OP=2 >> ../calculo_metricas/saida1.txt 
make -s run_test TEST_FILE=../mazes/maze5_5-4.txt OP=2 >> ../calculo_metricas/saida1.txt
make -s run_test TEST_FILE=../mazes/maze5_5-5.txt OP=2 >> ../calculo_metricas/saida1.txt

# calculo das metricas para o labirinto de tamanho 5x5
../calculo_metricas/metricas < ../calculo_metricas/saida1.txt >> ../calculo_metricas/metricas_BFS.txt


echo "\n\nLabirinto 10x10\n" >> ../calculo_metricas/metricas_BFS.txt
make -s run_test TEST_FILE=../mazes/maze10_10-1.txt OP=2 > ../calculo_metricas/saida2.txt
make -s run_test TEST_FILE=../mazes/maze10_10-2.txt OP=2 >> ../calculo_metricas/saida2.txt
make -s run_test TEST_FILE=../mazes/maze10_10-3.txt OP=2 >> ../calculo_metricas/saida2.txt 
make -s run_test TEST_FILE=../mazes/maze10_10-4.txt OP=2 >> ../calculo_metricas/saida2.txt
make -s run_test TEST_FILE=../mazes/maze10_10-5.txt OP=2 >> ../calculo_metricas/saida2.txt

# calculo das metricas para o labirinto de tamanho 10x10
../calculo_metricas/metricas < ../calculo_metricas/saida2.txt >> ../calculo_metricas/metricas_BFS.txt


echo "\n\nLabirinto 20x20\n" >> ../calculo_metricas/metricas_BFS.txt
make -s run_test TEST_FILE=../mazes/maze20_20-1.txt OP=2 > ../calculo_metricas/saida3.txt
make -s run_test TEST_FILE=../mazes/maze20_20-2.txt OP=2 >> ../calculo_metricas/saida3.txt
make -s run_test TEST_FILE=../mazes/maze20_20-3.txt OP=2 >> ../calculo_metricas/saida3.txt 
make -s run_test TEST_FILE=../mazes/maze20_20-4.txt OP=2 >> ../calculo_metricas/saida3.txt
make -s run_test TEST_FILE=../mazes/maze20_20-5.txt OP=2 >> ../calculo_metricas/saida3.txt

# calculo das metricas para o labirinto de tamanho 20x20
../calculo_metricas/metricas < ../calculo_metricas/saida3.txt >> ../calculo_metricas/metricas_BFS.txt

echo "\n\nLabirinto 50x50\n" >> ../calculo_metricas/metricas_BFS.txt
make -s run_test TEST_FILE=../mazes/maze50_50-1.txt OP=2 > ../calculo_metricas/saida4.txt
make -s run_test TEST_FILE=../mazes/maze50_50-2.txt OP=2 >> ../calculo_metricas/saida4.txt
make -s run_test TEST_FILE=../mazes/maze50_50-3.txt OP=2 >> ../calculo_metricas/saida4.txt 
make -s run_test TEST_FILE=../mazes/maze50_50-4.txt OP=2 >> ../calculo_metricas/saida4.txt
make -s run_test TEST_FILE=../mazes/maze50_50-5.txt OP=2 >> ../calculo_metricas/saida4.txt

# calculo das metricas para o labirinto de tamanho 50x50
../calculo_metricas/metricas < ../calculo_metricas/saida4.txt >> ../calculo_metricas/metricas_BFS.txt


echo "\n\nLabirinto 150x150\n" >> ../calculo_metricas/metricas_BFS.txt
make -s run_test TEST_FILE=../mazes/maze150_150-1.txt OP=2 > ../calculo_metricas/saida5.txt
make -s run_test TEST_FILE=../mazes/maze150_150-2.txt OP=2 >> ../calculo_metricas/saida5.txt
make -s run_test TEST_FILE=../mazes/maze150_150-3.txt OP=2 >> ../calculo_metricas/saida5.txt 
make -s run_test TEST_FILE=../mazes/maze150_150-4.txt OP=2 >> ../calculo_metricas/saida5.txt
make -s run_test TEST_FILE=../mazes/maze150_150-5.txt OP=2 >> ../calculo_metricas/saida5.txt

# calculo das metricas para o labirinto de tamanho 20x20
../calculo_metricas/metricas < ../calculo_metricas/saida5.txt >> ../calculo_metricas/metricas_BFS.txt



