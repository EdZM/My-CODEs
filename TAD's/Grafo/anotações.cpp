//#anotações dia 15/03/18

//- classes abstratas 
 
//ex:

	class stack {
		public: //
			virtual void push(int) = 0; // <---- isso NAO é uma atribuição. o "= 0" indica que o metodo é virtual PURO . O metodo virtual será usado já na superclasse
			virtual int pop()= 0; // metodos virtuais só fazem sentido se eu estiver trabalhando com Herança
			virtual int empty() = 0;

	};

/*
Obs.:

-using namespace std; é muito util quando pretendo usar varias funções  da biblioteca padrao

-using std::cout ---> especifico quais as funções da biblioteca padrao serão usadas naquele determinado codigo
-using std::endl

-Ao definir metodos virtuais, faça isso na superclasse já , pois isso evita a criação de novas classes

*/