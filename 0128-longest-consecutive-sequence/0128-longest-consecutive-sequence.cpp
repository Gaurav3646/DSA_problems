class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(), nums.end());
        int c = 1;
        int ans = 0;
        for(int i=1; i<nums.size(); i++){
           if(nums[i]-nums[i-1]<=1) c += nums[i]-nums[i-1];
            else{
                ans = max(c, ans);
                c = 1;
            }
        }
        ans = max(c, ans);
        return ans;
    }
};