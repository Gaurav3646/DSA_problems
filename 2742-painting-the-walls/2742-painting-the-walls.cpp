class Solution {
public:
    int solve(vector<int>& cost, vector<int>& time, int i, int t, vector<vector<int>> &dp){
        if(t>=501) return 0;
        if(i>=time.size()){
            if(t>=0) return 0;
            else return INT_MAX;
        }
        if(dp[i][t+501]!=-1) return dp[i][t+501];
        int ans = INT_MAX;
    
         ans = min(ans, solve(cost, time, i+1, t-1, dp));
         int include = solve(cost, time, i+1, time[i]+t, dp);
         ans = min(ans, include==INT_MAX?INT_MAX:cost[i]+include);
            return dp[i][t+501]=ans;
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
         vector<vector<int>> dp(cost.size()+1, vector<int>(1004, -1));
        return solve(cost, time, 0, 0, dp);
       
        // for(int i=time.size()-1; i>=0; i--){
        //     for(int j)
        // }
        
    }
};