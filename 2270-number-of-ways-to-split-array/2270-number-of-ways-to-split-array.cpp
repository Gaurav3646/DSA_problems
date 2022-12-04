class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
      long long sum;
        vector<long long> prefix(nums.size());
        prefix[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
           prefix[i] = nums[i] + prefix[i-1];
         }
        int count=0;
          sum = prefix.back();
        for(int i=0; i<nums.size()-1; i++){
            long long left = prefix[i];
            long long right = sum - prefix[i];
            if(left>=right){
                count++;
            }
        }
        return count;
    }
};