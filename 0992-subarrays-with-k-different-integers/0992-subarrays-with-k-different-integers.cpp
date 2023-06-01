class Solution {
public:
    int atMost(vector<int>&nums, int s){
        int res = 0, j=0;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i])==mp.end()) s--;
             mp[nums[i]] = i;
            while(s<0 && j<=i){
                if(mp[nums[j]]<=j){
                    mp.erase(nums[j]);
                    s = 0;
                }
                
                j++;
            }
            res += i-j+1;
                
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atMost(nums, k)-atMost(nums, k-1);
    }
};