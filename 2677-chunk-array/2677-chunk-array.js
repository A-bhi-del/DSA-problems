/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let list1 = [];
    let list2 = [];
    let len = arr.length;
    let s = 0;

    for(let i = 0; i < len; i++){
        list1.push(arr[i]);
        s++;
        if(s == size){
            list2.push(list1);
            s = 0;
            list1 = [];
        }
    }
    
    if(list1.length !== 0){
        list2.push(list1);
    }

    return list2;
};
