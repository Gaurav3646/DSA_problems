class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.length()+1, vector<int>(s2.length()+1));
        for(int i=1; i<=s1.size(); i++){
            dp[i][0] += s1[i-1] + dp[i-1][0];
        }
        for(int i=1; i<=s2.size(); i++){
            dp[0][i] += s2[i-1] + dp[0][i-1];
        }
       for(int i1=1; i1<=s1.length(); i1++){
          for(int i2=1; i2<=s2.length(); i2++){
             
             if(s1[i1-1]==s2[i2-1]){
                 dp[i1][i2] = dp[i1-1][i2-1];
             }
              else{
                 dp[i1][i2] = min({s1[i1-1]+dp[i1-1][i2], s2[i2-1]+dp[i1][i2-1]});        
              }
          }
      }
        // for(auto &d:dp){
        //     for(auto &v:d){
        //         cout<<v<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp.back().back();
    }
};