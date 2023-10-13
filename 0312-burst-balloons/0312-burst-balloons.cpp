class Solution {
public:
    int solve(vector<int>& nums, int i, int j,  vector<vector<int>>& dp){
         if(i==j){
             return nums[i]*nums[i+1]*nums[i-1];
         }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        for(int k=i; k<=j; k++){
            int maxi =(solve(nums, i, k-1, dp)+solve(nums, k+1, j, dp));
            ans = max(ans, nums[i-1]*nums[k]*nums[j+1]+maxi);
        }
        return dp[i][j] = ans;
        
     }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
       return solve(nums, 1, nums.size()-2, dp);
    }
};