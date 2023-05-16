/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
	return async function(...args) {
        return await new Promise(async(response, reject)=>{
    let timeOut = setTimeout(() => {
            reject('Time Limit Exceeded');
       }, t);
    
    try {
      let res = await fn(...args);
      clearTimeout(timeOut);
       response(res);
    } catch (err) {
        clearTimeout(timeOut);
        reject(err);
    }
    });
  };
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */