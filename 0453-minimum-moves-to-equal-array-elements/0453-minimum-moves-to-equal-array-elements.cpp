class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = INT_MAX;
      for(auto &num: nums){
          mini = min(num, mini);
      }
        long long ans = 0;
        for(auto &num: nums){
         ans += num-mini;
      }
        return ans;
    }
};