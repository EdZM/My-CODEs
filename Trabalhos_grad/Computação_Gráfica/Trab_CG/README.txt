COMO rodar o projeto 

Primeiro, as bibliotecas padr�o do OpenGL, as depend�ncias da GLFW e a GLM devem ser instaladas com o seguinte comando no terminal Linux: 
	sudo apt install libgl1mesa-dev xorg-dev libx11-dev libglm-dev 

A biblioteca GLAD tamb�m precisa ser instalada. Ela pode ser obtida no site https://glad.dav1d.de/. 

Para compilar, digite cmake .na pasta raiz do projeto, e depois make. Para executar, digite ./projeto1CPP.