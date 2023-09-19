class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int i=0;
        while(nums[i]!=nums[nums[i]]){
            if(nums[i]==i) i++;
            swap(nums[i], nums[nums[i]]);
        }
        return nums[i];
    }
};