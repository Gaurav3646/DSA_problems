class Solution {
public:
//     int M = 1e9+7;
//     int solve(string s, int k, int i, vector<int> &dp){
//        if(i>=s.length()){
//           return 1; 
//        } 
//         else if(s[i]=='0') return 0;
//         if(dp[i]) return dp[i];
       
//         for (long sz = 1, num = 0; i + sz <=s.size(); ++sz) {
//             num = num * 10 + s[i + sz-1] - '0';
//             if (num > k)
//                 break;
//             dp[i] = (dp[i] + solve(s,k, i + sz, dp)) % 1000000007;
//         }
//         return dp[i];
//     }
    
    int solveTab(string &s, int &k){
         vector<int> dp(s.length()+1, 0);
        dp[s.length()] = 1;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]=='0') continue;
            for (long sz = 1, num = 0; i + sz <=s.size(); ++sz) {
            num = num * 10 + s[i + sz-1] - '0';
            if (num > k)
                break;
            dp[i] = (dp[i] + dp[i + sz]) % 1000000007;
           }
        }
        return dp[0];
    }

    int numberOfArrays(string s, int k) {
        // vector<int> dp(s.length()+1, 0);
        // return solve(s, k, 0, dp);
        return solveTab(s, k);
       
        
        
    }
};