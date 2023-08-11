class Solution {
public:
    int solve(vector<int>& coins, int amount, int index,  vector<vector<int>> &dp){
        if(index>=coins.size()){
            if(amount==0) return 1;
            else return 0;
        }
        if(amount<0) return 0;
        if(dp[index][amount]!=-1) return dp[index][amount];
        int x = amount;
        int ans = 0;
        while(x>=0){
            x -= coins[index];
          ans+=  solve(coins, x, index+1, dp);
        }
       return dp[index][amount] = ans+ solve(coins, amount, index+1, dp);
    }
   
    int change(int amount, vector<int>& coins) {
        // return solve(coins, amount);
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
         return solve(coins, amount,0, dp);
    }
};