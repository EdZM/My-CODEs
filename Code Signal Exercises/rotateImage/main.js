// Solução eficiente do exercicio 3 do nivel iniciante do code Signal

var mat = [[1, 2, 3],
           [4, 5, 6],
           [7, 8, 9]]


function rotateImage(mat) {
  
  // transposição da matriz usando map ==> quando é preciso traduzir/mapear todos os elementos em um array para outro conjunto de valores
  mat = mat[0].map(function (col, c) {
    return mat.map(function (row, r) {
      return mat[r][c];
    });
  });

  // reversão dos elementos de cada linha da matriz
  var i = 0;
  while(1){
    if(mat[i] != undefined){
      mat[i].reverse();
      i++;
    } else {
      break;
    
    }
  }

}

