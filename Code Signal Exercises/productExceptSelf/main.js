var nums = [1,2,3,4];
var m = 12;

productExceptSelf(nums, m);

function productExceptSelf(nums, m) {
  
  var left_products = new Array(nums.length);
  var right_products = new Array(nums.length);
  var output_product = new Array(nums.length);
  var modulo = 0;
  
  for (let i = 0; i < nums.length; i++) {
    if(i === 0) left_products[i] = 1;
    else left_products[i] = nums[i - 1] * left_products[i - 1] ;
    
  }

  for (let i = nums.length-1; i >= 0; i--) {
    if (i === nums.length - 1) right_products[i] = 1;
    else right_products[i] = nums[i + 1] * right_products[i + 1];
    
  }

  for (let i = 0; i < nums.length; i++) {
    output_product[i] = left_products[i] * right_products[i];
    
  }

  modulo = output_product.reduce((a,b) => a+b);//realiza a soma dos elementos presentes em output_product
  console.log(modulo%m);
  return modulo % m;

}

// solução que funciona no codeSignal
// let p = 1, g = 0;
//   for (let i of nums) {
//     g = (g * i + p) % m;

//     p = (p * i) % m;
//   }
// console.log(g);
// return g;

//console.log(product);
//console.log(nums);