/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const newArr = new Array(arr.length);
    arr.forEach((val, ind)=>{
       newArr[ind] = fn(val, ind);
    })
    return newArr;
};