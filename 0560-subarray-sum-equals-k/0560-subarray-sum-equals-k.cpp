class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    // vector<int> prefix(nums.size()+1);
    //   prefix[1] = nums[0];
    // for(int i=1; i<nums.size(); i++){
    //     prefix[i+1] = nums[i] + prefix[i]; 
    // }
    unordered_map<int, int> mp;
     int ans = 0;
     int sum =0;
    for(int i=0; i<nums.size();  i++){

         mp[k+sum]++;
         sum += nums[i];
        if(mp.find(sum)!=mp.end()){
            ans += mp[sum];   
        }
        
        
    }
    return ans;
    }
};