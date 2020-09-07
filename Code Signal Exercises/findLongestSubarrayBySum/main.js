// A ideia encontrar o maior subarray que é possível formar com o array fornecido por parametro que gere um determinado valor de soma por meio de seus elementos
// A solução pensada foi: percorrer o array uma unica vez usando 'ponteiros' que marcam os limites de direita e esquerda do subarray.
//                        quando obtiver um subarray cujos elementos resultem na soma fornecida, deve-se avaliar se esse tem o maior tamanho em relação aos demais que forem encontrados


var arr = [1, 2, 3, 4, 5, 0, 0, 0, 6, 7, 8, 9, 10];
//var arr = [1, 2, 3, 7, 5];
var sum = 15;

function findLongestSubarrayBySum(arr, sum) {

  var range = [];

  range[0] = -1;

  var right = 0;
  var left = 0;
  var current_sum = 0;


  while(right < arr.length){
    current_sum += arr[right];
    while (left < right && current_sum > sum) {
      current_sum -= arr[left++];
    }

    if (current_sum == sum && (range.length == 1 || range[1] - range[0] < right - left)){
      range = new Array(left + 1, right + 1);

    }
    right++;

  }
  
  return range ;



}