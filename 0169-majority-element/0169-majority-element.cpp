class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //  int count = 1;
        // int x = -1;
        // sort(nums.begin(), nums.end());
        // for(int i=1; i<nums.size(); i++){
        //     if(nums[i]==nums[i-1]){
        //         x = nums[i-1];
        //         count++;
        //     }
        //     else{
        //         int n = nums.size()/2;
        //         if(count>n){
        //             return x;
        //         }
        //         count = 1;
        //     }
        // }
        //  if(nums.size()==1){
        //     return nums[0];
        // }
        // return x;
        
        
        
        
       // moore voting algo
     // majority element always exists
        
        int count = 0;
        int el;
        for(int i=0; i<nums.size(); i++){
            if(count == 0){
               count++;
                el = nums[i];
            }
            else if(el==nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        return el;
            
    }
};