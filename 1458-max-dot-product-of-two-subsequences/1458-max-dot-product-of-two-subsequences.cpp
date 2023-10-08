class Solution {
public:
//     int solve(vector<int> &nums1, vector<int> &nums2, int i1, int i2){
//         if(i1>=nums1.size() || i2>=nums2.size()){
//             return 0;
//         }
        
//         // cout<<nums1[i1]*nums2[i2]<<endl;
//         return ans;
        
//     }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
         int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;
        
        for (int num: nums1) {
            firstMax = max(firstMax, num);
            firstMin = min(firstMin, num);
        }
        
        for (int num: nums2) {
            secondMax = max(secondMax, num);
            secondMin = min(secondMin, num);
        }
        
        if (firstMax < 0 && secondMin > 0) {
            return firstMax * secondMin;
        }
        
        if (firstMin > 0 && secondMax < 0) {
            return firstMin * secondMax;
        } 

    
        // return solve(nums1, nums2, 0, 0);
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1));
        
        for(int i1=nums1.size()-1; i1>=0; i1--){
            for(int i2=nums2.size()-1; i2>=0; i2--){
            int ans = INT_MIN;
         ans = max(ans, dp[i1+1][i2]);
         ans = max(ans, dp[i1][i2+1]);
         ans = max(ans, nums1[i1]*nums2[i2] + dp[i1+1][i2+1]);
                dp[i1][i2] = ans;
            }
        }
        return dp[0][0];
    }
};