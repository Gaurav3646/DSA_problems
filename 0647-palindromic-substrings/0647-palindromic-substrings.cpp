class Solution {
public:
    // int memo[1000][1000] = {0};
    // int longestPalindromeSubseq(const string& s) {
    //     return dp(s, 0, s.size() - 1);
    // }

    int countSubstrings(string s) {
        int n = s.length();
      vector dp(n, vector<int>(n , 0));
        int count =0;
        for(int i=0; i<n; i++){
            for(int j=i; j>=0; j--){
                if(j==i){
                    dp[j][i] = 1;
                }
                else if(j+1==i){
                    dp[j][i] = s[j]==s[i];
                }
                else{
                    dp[j][i] = s[j]==s[i]&&dp[j+1][i-1];
                }
                // cout<<dp[j][i]<<j<<" "<<i<<endl;
              count += dp[j][i];  
            }
        }
        return count;
    }
};