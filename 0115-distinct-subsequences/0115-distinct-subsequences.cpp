class Solution {
public:
   
    int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        if(i>=t.size()){
            
            return 1;
        }
        if(j>=s.size()) return 0;
        if(dp[j][i]!=-1) return dp[j][i];
        int ans =0;
        if(t[i]==s[j]){
          ans +=  solve(s, t, i+1, j+1, dp);
        }
       ans += solve(s, t, i, j+1, dp);
        return dp[j][i] = ans;
        
    }
    int numDistinct(string s, string t) {
                vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, -1));
        return  solve(s, t, 0, 0, dp);
       

//       for(int i=0; i<s.size(); i++){
//             for(int j=0; j<t.size(); j++){
//                if(s[i]==t[j]){
                   
//                }

//             }
//       }
    }
};