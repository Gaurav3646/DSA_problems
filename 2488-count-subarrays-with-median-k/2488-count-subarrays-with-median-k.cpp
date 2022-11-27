class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
       unordered_map<int, int> c;
        c[0] = 1;
        bool has = false;
        int sum = 0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<k) sum--;
            else if(nums[i]>k) sum++;
            else has = true;
            if(has) ans += c[sum]+c[sum-1];
            else c[sum]++;
        }
        return ans;
    }
};