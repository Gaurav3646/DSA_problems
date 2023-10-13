class Solution {
public:
    int solve(vector<int> &cost, int j){
        if(j>=cost.size()) return 0;
        int mini = INT_MAX;
        mini = min(mini, solve(cost, j+1));
        mini = min(mini, solve(cost, j+2));
        return mini + cost[j];
    }
    int minCostClimbingStairs(vector<int>& cost) {
      // cost.insert(cost.begin(), 0);
       // return solve(cost, 0);
        vector<int> dp(2, 0);
    for(int j=cost.size()-1; j>=0; j--){
       int mini = min(dp[1], dp[0]);
            dp[1] = dp[0];
         dp[0] = mini + cost[j];
        }
        return min(dp[0], dp[1]);
    }
};