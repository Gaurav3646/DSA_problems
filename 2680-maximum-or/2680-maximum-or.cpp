class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
       vector<long long> left(nums.size());
         vector<long long> right(nums.size());
        long long ors =0;
        for(int i=0; i<nums.size(); i++){
            left[i] = ors;
            ors |= nums[i];
            
        }
         ors = 0;
        for(int i=nums.size()-1; i>=0; i--){
            right[i] = ors;
            ors |= nums[i];
            
        }
        long long maxi = 0;
        int ind = -1;
        long long power = pow(2, k);
        for(int i=0; i<nums.size(); i++){
            long long x = nums[i]*power;
            x = x|left[i]|right[i];
            if(x>maxi){
                ind = i;
                maxi = x;
            }
            
        }
       
    
      long long  ans = maxi|left[ind]|right[ind];
        return ans;
        
    }


};