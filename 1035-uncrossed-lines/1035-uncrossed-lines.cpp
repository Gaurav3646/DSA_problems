class Solution {
public:
    int solve(int i1, int i2, vector<int>& nums1, vector<int>& nums2,  vector<vector<int>>& dp){
        if(i1>=nums1.size() || i2>=nums2.size()) return 0;
        int ans = 0;
        if(dp[i1][i2]!=-1) return dp[i1][i2];
       
        if(nums1[i1]==nums2[i2]){
          ans =  1+ solve(i1+1, i2+1, nums1, nums2, dp);
        }
        ans = max(ans, solve(i1+1, i2, nums1, nums2, dp));
        ans = max(ans, solve(i1, i2+1, nums1, nums2, dp));
        return dp[i1][i2] = ans;

    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
         int n2 = nums2.size();
//         vector<vector<int>> dp(n1, vector<int>(n2, -1));    

//         return solve(0,0, nums1, nums2, dp);
    
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0)); 
        
      for(int i1=n1-1; i1>=0; i1--){
          for(int i2=n2-1; i2>=0; i2--){
                int ans = 0;
                if(nums1[i1]==nums2[i2]){
                  ans =  1+ dp[i1+1][i2+1];
                }
                ans = max(ans, dp[i1+1][i2]);
                ans = max(ans, dp[i1][i2+1]);
                dp[i1][i2] = ans;
              
          }
      }
        return dp[0][0];
        
    }
    
};