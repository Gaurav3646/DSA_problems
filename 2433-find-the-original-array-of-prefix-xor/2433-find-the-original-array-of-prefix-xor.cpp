class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans(pref.size());
      int sumx = 0;
       int curr = 0;
        for(int i=0; i<pref.size(); i++){
            curr = pref[i]^sumx;
            ans[i] = curr;
            sumx ^= curr;
             
        }
        return ans;
    }
};