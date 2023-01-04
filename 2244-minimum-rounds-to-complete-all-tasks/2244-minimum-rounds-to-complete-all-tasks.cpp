class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
    unordered_map<int, int> mp;
        for(auto &t:tasks){
          mp[t]++;
        }
        int ans = 0;
        for(auto &feq:mp){
            int f = feq.second;
            if(f==1) return -1;
            int t = f/3;
            int rem = f%3;
            ans += t;
            if(rem==2||rem==1){
               ans += 1;
            } 
        }
        return ans;
    }
};