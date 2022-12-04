class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
      long long totalSum=0;
        // vector<long long> prefix(nums.size());
        // prefix[0] = nums[0];
        // for(int i=1; i<nums.size(); i++){
        //    prefix[i] = nums[i] + prefix[i-1];
        //  }
       for(int i=0; i<nums.size(); i++){
          totalSum += nums[i];
       }
        int count=0;
          long long left = 0;
         long long  right = totalSum;
        for(int i=0; i<nums.size()-1; i++){
             left += nums[i];
            right -= nums[i];
            if(left>=right){
                count++;
            }
        }
        return count;
    }
};