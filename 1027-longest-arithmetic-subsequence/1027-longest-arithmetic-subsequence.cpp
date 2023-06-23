class Solution {
public: 
//     int solve2(int i, int d, vector<int>& nums, unordered_map<int, int> dp[]){
//         if(i<0){
//             return 0;
//         }
//         if(dp[i].count(d)){
//             return dp[i][d];
//         }
//         int sum = 0;
//            for(int j=i-1; j>=0; j--){
//                if(nums[i]-nums[j]==d){
//                  sum = max(sum, 1+ solve2(j, d, nums, dp));
//                }
//            }
//         dp[i][d] = sum;
//         return sum;
    
//     }
//    int solve(vector<int>& nums){
//      int ans =0;
//        unordered_map<int, int> dp[nums.size()+1];
//        for(int i=0; i<nums.size()-1; i++){
//            for(int j=i+1; j<nums.size(); j++){
//               ans =  max(ans, 2+solve2(i, nums[j]-nums[i], nums, dp));
//            }
//        }
//        return ans;
      
//    }
      int solve(vector<int>& nums, int diff){
//      int ans =0;
//        vector<vector<int>> dp(nums.size()+1, vector<int>(2*diff+2, 1));
//        for(int i=1; i<nums.size(); i++){
          
//            for(int j=0; j<i; j++){
//               int d = nums[i]-nums[j];
             
//               dp[i][d+diff] = 1+dp[j][d+diff];
//                ans = max(ans, dp[i][d+diff]);
//            }
//        }
//        return ans;
      
          int ans= 0;
          vector<vector<int>> dp(nums.size()+1, vector<int>(2*diff+2, 1));
          for(int i=0; i<nums.size(); i++){
              for(int j=0; j<i; j++){
                  int d = nums[i]-nums[j];
                  dp[i][diff+d] = 1+ dp[j][diff+d];
                  ans = max(ans, dp[i][diff+d]);
              }
          }
          return ans;
   }
    int longestArithSeqLength(vector<int>& nums) {
         // brute force approach
//         int max = 2;
//        for(int i=0; i<nums.size(); i++){
//             if(max>=nums.size()-i-1){
//                break;
//            }
//            for(int j=i+1; j<nums.size(); j++){
//                int n = 2;
//                int d = nums[j]-nums[i];
//                for(int k=j+1; k<nums.size(); k++){
//                    if(nums[k]-nums[i]==n*d){
//                        n++;
//                    }
//                }
//                if(max<n){
//                    max = n;
//                }
//            }
          
//        }
//         return max;
        vector<int> nums2 = nums;
        sort(nums2.begin(), nums2.end());
        int diff = nums2[nums2.size()-1]-nums2[0];
       return solve(nums, diff);
    }
};