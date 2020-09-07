
var a = [1, 2, 3];
var b = [10, 20, 30, 40];
var v = 42;

// Solução mais rápida. (usando set, cujo metodo add usa uma abordagem de implementação da tabela de hash)
function sumOfTwo (a, b, v) {
//module.exports = function sumOfTwo(a,b,v) {    
    var list = new Set();
    //var list = [];


    for (let i of a){
        list.add(v - i); // essa operação é mais rapida do que o push de um array
        //list.push(v - i); 
    }

    for (let i of b) {
        if(list.has(i)) return true;
        //if (list.includes(i)) return true;
    }

    return false;    
}


/*
// Solução mais lenta

function sumOfTwo(a, b, v) {

    var dif;

    for (let i of a){
        dif = v - i;
        if(b.includes(dif)){
            return true;
        }

    }
    return false;

}

*/

/* 
// melhor solução do code signal em javascript

sumOfTwo = (a, b, v) => ( // arrow function
    b = new Set(b), // transforma b em uma estrutura de dados chamada set
    a.some(e => b.has(v - e)) // some é um metodo que checa(não altera nada) se algum elemento 'e' do array 'a' é "aprovado" pela arrow function
                              // se algum elemento 'passar no teste', some retorna true, caso contrario retorna false
    )

*/