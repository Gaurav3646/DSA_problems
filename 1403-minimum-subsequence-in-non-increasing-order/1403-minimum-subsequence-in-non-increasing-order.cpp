class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
   int sum  = 0;
        for(auto &n : nums){
            sum += n;
        }
        int subSum = 0;
        vector<int> ans;
        for(int i=nums.size()-1; i>=0; i--){
           ans.push_back(nums[i]);
            subSum += nums[i];
            if(subSum>(sum-subSum)){
                return ans;
            }
        }
        return ans;

    }
};