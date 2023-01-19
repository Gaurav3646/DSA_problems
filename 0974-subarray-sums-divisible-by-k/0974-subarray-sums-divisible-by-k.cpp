class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
         int x = 0;
       unordered_map<int, int> mp;
        mp[0] = 1;
        for(int i=0; i<nums.size(); i++){
            x = (x+nums[i]%k+k)%k;
             ans += mp[x%k];
               mp[x%k]++;
          
        }
        return ans;
    }
};