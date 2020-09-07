var arr = [-1,2,-3,1];


containsDuplicates(arr);

function containsDuplicates(a) {
    var list = new Set();

    for (let i of a) {
            
        if(list.has(i)){
            console.log('true');
            return true;
        } else {
    
            list.add(i);
        }
    
    }
    
    console.log('false');
    return false;
}
