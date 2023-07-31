class Solution {
public:
int solve(string &text1, string &text2){
        vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, 0));
        
    for(int i=text1.length()-1; i>=0; i--)                 // base case filling up
        dp[i][text2.length()] = dp[i+1][text2.length()] + text1[i];

    for(int j=text2.length()-1; j>=0; j--)                 // base case filling up
        dp[text1.length()][j] = dp[text1.length()][j+1] + text2[j];
    
        for(int i1=text1.length()-1; i1>=0; i1--){
       for(int i2=text2.length()-1; i2>=0; i2--){
           int mx = INT_MAX;
        if(text1[i1]==text2[i2]){
          mx = min(mx, dp[i1+1][i2+1]);
        }
        else{
            
           mx = min(text1[i1] + dp[i1+1][i2], text2[i2]+dp[i1][i2+1]);
        }
          
         dp[i1][i2] = mx;  
            // cout<<dp[i1][i2]<<endl;
       }
        }
    
//     for(int i=0; i<dp.size(); i++){
//         for(int j=0; j<dp[0].size(); j++){
//             cout<<dp[i][j]<<" ";
//         }
//         cout<<endl;
//     }
        return dp[0][0];
    }
    int minimumDeleteSum(string s1, string s2) {
     return solve(s1, s2);  
    }
};