class Solution {
public:
    // bool solve(vector<int> &nums, int i, vector<int> &dp){
    //     if(i>=nums.size()-1){
    //         return true;
    //     }
    //     if(dp[i]!=-1){
    //         return dp[i];
    //     }
    //     int ans = false;
    //     int n = nums.size()-i-1;
    //     int mn =  min(nums[i],n);
    //     for(int j=1; j<=mn; j++){
    //         if(ans==true){
    //             return true;
    //         }
    //        ans |= solve(nums, i+j, dp); 
    //     }
    //     return dp[i] = ans;
    // }
//     void  solve(vector<int> &nums, int i, bool &myans, vector<int> &dp){
//         if(i>=nums.size()-1){
//             myans = true;
//             return ;
//         }
//            if(myans==true){
//                return ;
//            }
      
//         int n = nums.size()-i-1;
//         int mn =  min(nums[i],n);
//         for(int j=1; j<=mn; j++){
//            solve(nums, i+j, myans); 
//         }
      
//         return ;
//     }
//     bool solveOp(vector<int> &nums){
//           vector<bool> dp(nums.size(), false);
//         dp[nums.size()-1] = true;
//         for(int i=nums.size()-1; i>=0; i--){
//               int ans = false;
//             for(int j=nums[i]; j>=1; j--){
                  
//                   ans |= solve(nums, i+j, dp);   
//             }
//         }
        
//      }
    
   bool valleyPeakApproach(vector<int>& nums, int &max){
        for(int i=0; i<nums.size(); i++){
            if(max<i){
                return false;
            }
            if(max<(nums[i]+i)){
                max = nums[i]+i;
            }
        }
       return true;
       // if(max>=nums.size()-1){
       //     return true;
       // }
       // return false;
       
    }
    bool canJump(vector<int>& nums) {
        
       //  vector<int> dp(nums.size(), -1);
       //  bool ans = false;
       //  solve(nums, 0, ans, dp);
       //  return ans;
       // // return solve(nums);
        int max = 0;
        return valleyPeakApproach(nums, max);
     
    }
};