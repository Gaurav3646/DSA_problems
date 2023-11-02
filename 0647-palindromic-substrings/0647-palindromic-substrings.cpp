class Solution {
public:
    int countSubstrings(string s) {
        
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, 0));
          int ans=0;
        for(int i=0; i<s.size(); i++){
            dp[i][i] = 1;
            ans++;
        }
       for(int i=0; i<s.size()-1; i++){
            dp[i][i+1] = s[i]==s[i+1];
            ans += s[i]==s[i+1];
       }
        
        for(int gap=2; gap<s.size(); gap++){
          for(int i=0; i<s.size()-gap; i++){
              int j= i+gap;
              dp[i][j] = s[i]==s[j]?dp[i+1][j-1]:0;
             ans += dp[i][j]; 
          }  
        }
        return ans;
       
    }
};