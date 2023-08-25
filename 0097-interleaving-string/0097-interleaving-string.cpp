class Solution {
public:
    bool solve(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<int>> &dp){
        if(k>=s3.size() && j>=s2.size() && i>=s1.size()){
            return true;
        }
        if(k>=s3.size() && (j<s2.size() || i<s1.size())){
            return false;
        }
        if(dp[j][k]!=-1) return dp[j][k];
        bool ans = false;
        // cout<<s[i]<<s[j]<<s[k]<<endl;
        if(s2[j]==s3[k]){
            ans |= solve(s1, s2, s3, i, j+1, k+1, dp);
        }
        if(s1[i]==s3[k]){
          ans |= solve(s1, s2, s3, i+1, j, k+1, dp);
        }
        return dp[j][k] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s2.size()+1, vector<int>(s3.size()+1, -1));
      return solve(s1, s2, s3, 0, 0, 0, dp);
    }
};