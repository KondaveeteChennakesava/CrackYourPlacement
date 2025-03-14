/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    return function(x) {
        if(!functions) return x;
        let idx = functions.length - 1;
        let ans = x;
        while(idx > -1){
            ans = functions[idx](ans);
            idx--;
        }
        return ans;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */