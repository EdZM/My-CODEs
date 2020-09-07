#!/bin/sh

git clone URL_repo
cd /path/to/dir/ #colocar o caminho para a raiz do repositório
git add . #adiciona a pasta atual
git commit -m "<mensagem>"
git push origin master


#OBS.: antes de rodar o script abra ele no vim e o converta para arquivo de texto compatível com UNIX (comando -> :set ff=unix)
