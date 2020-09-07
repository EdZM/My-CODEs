var nums = [3, 0, -2, 6, -3, 2];
var queries = [[2, 5],
               [0, 2],
               [0, 5]];

sumInRange(nums, queries);


function sumInRange(nums, queries) {

  var pre_sum = 0;
  var sum = 0;
  const partials = nums.map((n) => pre_sum += n); // cada posição tem a soma da posição 0 ate a posição i

  sum = queries.reduce((first_sum, query) => { // reduz cada linha da matriz queries
    first_sum += partials[query[1]] - (query[0] != 0 ? partials[query[0] - 1] : 0);

    return first_sum < 0 ? first_sum + (1e9 + 7) : first_sum % (1e9 + 7);
  
  }, 0);

  return sum;

  

}

