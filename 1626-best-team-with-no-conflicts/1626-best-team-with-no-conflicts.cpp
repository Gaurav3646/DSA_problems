class Solution {
public:
    int solve(vector<pair<int, int>> &baskets, int curr, int prev, vector<vector<int>> &dp){
        if(curr>=baskets.size()) return 0;
        
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        // take
        int take = 0;
        if(prev==-1 || baskets[prev].second<=baskets[curr].second){
            take = baskets[curr].second + solve(baskets, curr+1, curr, dp);
        }
        int ntake = solve(baskets, curr+1, prev, dp);
        return dp[curr][prev+1] = max(take, ntake);
        //ntake;
        
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> baskets;
        vector<vector<int>> dp(scores.size()+1, vector<int>(scores.size()+1, -1));
        for(int i=0; i<scores.size(); i++){
            baskets.push_back({ages[i], scores[i]});
        }
        sort(baskets.begin(), baskets.end());
        return solve(baskets, 0, -1, dp);
    }
};