/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let ans = []
    arr.forEach((item, i)=>{
        ans[i] = fn(item, i);
    })
    return ans;
};