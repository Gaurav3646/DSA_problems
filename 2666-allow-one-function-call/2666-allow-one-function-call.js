/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    var once = true;
    return function(...args){
        var val;
        if(once){
        val = fn(...args);
            once = false;
        }
        return val;

    }
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
