class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> mp;
        for(auto &n:nums){
            mp[n]++;
        }
        int ans =0;
        int i =0;
        for(auto &it:mp){
            ans += it.second*i;
            i++;
        }
        return ans;
    }
};