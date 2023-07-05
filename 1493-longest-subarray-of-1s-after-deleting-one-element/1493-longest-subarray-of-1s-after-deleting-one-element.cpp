class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int j = 0;
        int ans = 0;
        bool z = false;
        bool del = false;
        for(int i=0; i<nums.size();){
            if(nums[i]){
                i++;    
           }
           else if(!z){
                i++;
               del = true;
                z = true;
           }
            else {
               if(!nums[j]){
                 
                   z = false;
               }
                  j++;
            }
           ans = max(ans, i-j-z); 
            
        }
        
        return del?ans:ans-1;
    }
};