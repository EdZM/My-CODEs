#!/bin/sh

git clone URL_repo
cd /path/to/dir/ #colocar o caminho para a raiz do repositório
git rm -r /path/to/dir/ #caminho do que se deseja deletar (arquivo ou pasta)
git commit -m "removendo"
git push origin master

#OBS.: antes de rodar o script abra ele no vim e o converta para arquivo de texto compatível com UNIX (comando -> :set ff=unix)