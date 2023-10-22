class Solution {
public:
    int minimumSum(vector<int>& nums) {
        vector<int> left(nums.size());
        vector<int> right(nums.size());
         left[0] = nums[0];
        right.back() = nums.back();
        for(int  i=1; i<nums.size(); i++){
            right[nums.size()-i-1] = min(nums[nums.size()-i-1], right[nums.size()-i]);
            left[i] = min(nums[i], left[i-1]);
        }
        int ans = INT_MAX;
        for(int i=1; i<nums.size()-1; i++){
            cout<<nums[i]<<" "<<left[i-1]<<" "<<right[i+1]<<endl;
            if(nums[i]>right[i+1] && nums[i]>left[i-1])
            ans = min(ans, (nums[i]+right[i+1]+left[i-1]));
        }
        return ans!=INT_MAX?ans:-1;
    }
};