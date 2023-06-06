class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long x = nums[1] - nums[0];
        for(int i=2; i<nums.size(); i++){
            if(x!=(long long)(nums[i]-nums[i-1])) return false;
            
        }
        return true;
    }
};