class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
       unordered_map<long long,int> dp[nums.size()];
        long long ans = 0;
        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                long d = (long long) nums[i]-nums[j];
                int count = dp[j].count(d)?dp[j][d]:0;
                dp[i][d] += count+1;
                ans += count;
                
            }
           // ans += dp[i][d];
        }
        return ans;
    }
};