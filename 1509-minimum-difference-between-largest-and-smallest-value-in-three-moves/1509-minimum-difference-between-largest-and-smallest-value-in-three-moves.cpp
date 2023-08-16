class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4) return 0;
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for(int i=3,  j= nums.size()-1; i>=0; --i, --j){
            
            ans = min(nums[j]-nums[i], ans);
        }
        return ans;
    }
};