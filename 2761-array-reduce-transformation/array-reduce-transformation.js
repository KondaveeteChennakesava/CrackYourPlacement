/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let ans = init;
    nums.forEach((item, i)=>{
        ans = fn(ans, item);
    })
    return ans;
};