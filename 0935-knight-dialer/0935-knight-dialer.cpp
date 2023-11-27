class Solution {
public:
    vector<vector<int>> memo;
     int MOD = 1e9 + 7;
    int dfs(vector<vector<int>> &adj , int v, int n){
        if(n<=0) return 1;
         if (memo[n][v] != 0) {
            return memo[n][v];
        }
        
        int ans = 0;
       for(int &u: adj[v]){
           ans = (ans + dfs(adj, u, n-1))%MOD;
       }
         memo[n][v] = ans;
        return ans;
        
    }
    int knightDialer(int n) {
       vector<vector<int>> adj = {{4, 6}, {6, 8}, {9, 7}, {8, 4},{3, 9, 0},  {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};
        memo = vector(n + 1, vector(10, 0));
         int ans =0;
       
           for(int i=0; i<10; i++){
             ans =  (ans + dfs(adj, i, n-1))%MOD;
           }
        
        return ans;
    }
};