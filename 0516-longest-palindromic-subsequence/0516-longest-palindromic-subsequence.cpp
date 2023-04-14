class Solution {
public:
    //     int  solve(string text1, string text2, int i1, int i2, vector<vector<int>> &dp){
//            if(i1>=text1.length()||i2>=text2.length()){
//                return 0;
//            }
//         if(dp[i1][i2]!=-1){
//             return dp[i1][i2];
//         }
//         int mx = INT_MIN;
//         if(text1[i1]==text2[i2]){
//           mx = max(mx, 1+ solve(text1, text2, i1+1, i2+1, dp));
//         }
//         else{
//            mx = max(solve(text1, text2, i1+1, i2, dp),  solve(text1, text2, i1, i2+1, dp));
            
//         }
//         return dp[i1][i2] = mx;
//         }
    int solveTab(string text1, string text2){
        vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, 0));
        for(int i1=text1.length()-1; i1>=0; i1--){
       for(int i2=text2.length()-1; i2>=0; i2--){
           int mx = INT_MIN;
        if(text1[i1]==text2[i2]){
          mx = max(mx, 1+ dp[i1+1][i2+1]);
        }
        else{
           mx = max(dp[i1+1][i2],  dp[i1][i2+1]);
            
        }
         dp[i1][i2] = mx;   
       }
        }
        return dp[0][0];
    }
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());
        //  vector<vector<int>> dp(s1.length(), vector<int>(s.length(), -1));
       // return solve(s1, s, 0, 0, dp);
        return solveTab(s1, s);
       
    }
};