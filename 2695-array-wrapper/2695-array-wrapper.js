/**
 * @param {number[]} nums
 * @return {void}
 */
var ArrayWrapper = function(nums) {
    this.nums = nums;
};

/**
 * @return {number}
 */
ArrayWrapper.prototype.valueOf = function() {
    let sum = 0;
    for(let val of this.nums){
        sum += val;
    }
    return sum;
}

/**
 * @return {string}
 */
ArrayWrapper.prototype.toString = function() {
    let str = "[";

    for(let val of this.nums){
        str += String(val);
        str += ",";
    }

    if(str === "["){
        return "[]";
    }
    
    str = str.slice(0,-1);
    str += "]";

    return str;
}

/**
 * const obj1 = new ArrayWrapper([1,2]);
 * const obj2 = new ArrayWrapper([3,4]);
 * obj1 + obj2; // 10
 * String(obj1); // "[1,2]"
 * String(obj2); // "[3,4]"
 */