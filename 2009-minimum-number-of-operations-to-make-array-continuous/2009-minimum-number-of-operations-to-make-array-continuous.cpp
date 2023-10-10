
class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(nums.size()==1) return 0;
        
        sort(nums.begin(), nums.end());
        
        int ans = nums.size();
        int count = 1;
        int j=0;
        
        for(int i=1; i<nums.size();){
            if(nums[i]-nums[i-1]==0){
                i++;
            } 
          else if(nums[i]-nums[j]<nums.size()){
               count++;
               i++;
           }
           else{
               j++;
              if(nums[j]!=nums[j-1])
                count--;
            }
            int x = nums.size();
           ans = min(ans, x-count); 
        }
        return ans;
    }
};