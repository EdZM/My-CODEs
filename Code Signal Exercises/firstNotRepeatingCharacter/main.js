function firstNotRepeatingCharacter(s) {
  const array = s.split("");
  let scores = new Array(array.length).fill(0); // contagem de ocorrencias dos caracteres da string

  for (let char of array) {
    scores[array.indexOf(char)]++;
    
  }
  
  const singleChar = array[scores.indexOf(1)]; // pega a posição primeiro valor 1 do scores e indexa o array que contem a string inicial
  
  console.log(scores);
  console.log(singleChar);
  
  return singleChar ? singleChar : "_"
}