/**
 * @param {Function} fn
 */
function memoize(fn) {
    let memo = [];
    return function(...args) {
        if(args.join(',') in memo) return memo[args.join(',')];
        const ans = fn(...args);
        memo[args.join(',')] = ans;
        return ans;
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */