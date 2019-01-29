#!/bin/sh

#git clone URL_repo
cd /mnt/c/Users/eduar/Documents/hello-world #colocar o caminho para a raiz do repositório
ls
git remote add asm_shurables /mnt/c/Users/eduar/Documents/asm-bitwise-trie #(cria um link para um repositório remoto especificado por sua URL do git)
# ou use git remote add asm_shurables URL do repositorio

git fetch asm_shurables --tags #(atualiza as referências locais com relações às remotas, mas não faz o merge com o branch local)
git merge --allow-unrelated-histories asm_shurables/master #(ou qualquer outra branch que se deseja copiar)
#git commit -m "<mensagem>"
git push origin master
git remote remove asm_shurables

#OBS.: antes de rodar o script abra ele no vim e o converta para arquivo de texto compatível com UNIX (comando -> :set ff=unix)

	
