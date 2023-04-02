class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        sort(potions.begin(), potions.end());
        vector<int> ans(n);
        int sz = potions.size();
        for(int i=0; i<n; i++){
            long long x = ceil((double)success/spells[i]);
           int  y = lower_bound(potions.begin(), potions.end(), x)-potions.begin();
            // cout<<x<<" "<<y<<endl;
           ans[i] = sz-y;
        }
        return ans;
    }
};