class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<unordered_map<long long, int>> dp(nums.size());
        int ans=0;
        for(int i=1; i<nums.size(); i++){
            long long d = (long long)nums[i]-nums[i-1];
            int count = dp[i-1].count(d)?dp[i-1][d]:0;
            dp[i][d] += count+1;
            ans += count;
        }
       return ans; 
    }
};