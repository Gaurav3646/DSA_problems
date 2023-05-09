/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
   const filteredArray = []
   var j =0;
   for(var i=0; i<arr.length; i++){
      if(fn(arr[i], i)) filteredArray[j++] = arr[i]; 
   }
    return filteredArray;
};