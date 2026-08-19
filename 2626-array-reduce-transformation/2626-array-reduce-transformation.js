/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let sum = init;
    if(nums.length == 0){
        return init;
    }

    nums.forEach((val) => {
        sum = fn(sum, val);
    })

    return sum;
};