class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
       vector<long long> left(nums.size());
         vector<long long> right(nums.size());
        long long orsLeft =0;
        long long orsRight =0;
        for(int i=0; i<nums.size(); i++){
            left[i] = orsLeft;
            right[nums.size()-1-i] = orsRight;
            orsLeft |= nums[i];
            orsRight |= nums[nums.size()-1-i];
            
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