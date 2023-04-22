class Solution {
public:
    // int solve(string s, int f, int e,  vector<vector<int>> &dp){
    //     if(f>=e) return 0;
    //     int x = 0;
    //        if(dp[f][e]!=-1) return dp[f][e];
    //         if(s[f]!=s[e]){
    //         int y =  1+ solve(s, f+1, e, dp);
    //          int z = 1+ solve(s, f, e-1, dp);
    //             x += min(y, z);
    //         }
    //         else{
    //             x += solve(s, f+1, e-1, dp);
    //         }
    //     return dp[f][e]= x;
    // }
    
    int TabSolve(string s){
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int f=n-1; f>=0; f--){
            for(int e=f+1; e<n; e++){
                if(s[f]!=s[e])
             dp[f][e] = 1+ min(dp[f+1][e], dp[f][e-1]);
                else
              dp[f][e] = dp[f+1][e-1];
            }
        }
        return dp[0][n-1];
    }
    int minInsertions(string s) {
      // int f = 0;
      // int e = s.size()-1;
      //   vector dp(e+1, vector<int>(e+1, -1));
        // return solve(s, f, e, dp);
        return TabSolve(s);
    }
};