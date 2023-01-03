class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max = nums[0];
        int count = 0;
        for(int i=1; i<nums.size(); i++){
          if(nums[i]<=max){
             
              count += (max-nums[i]+1);
              max++; 
          }
            else{
                max = nums[i];
            }
        }
        return count;
    }
};