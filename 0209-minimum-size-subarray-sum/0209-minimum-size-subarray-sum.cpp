class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int sum = 0;
        int mini = INT_MAX;
        for(int j=0; j<nums.size(); j++){
            sum += nums[j];
            while(target<=(sum-nums[i])){
                sum -= nums[i++];
            } 
            if(target<=sum)
            mini = min(mini, j-i+1);
        }
        return mini==INT_MAX?0:mini;
    }
};