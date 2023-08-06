class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        int l = nums.size();
        int ans = nums.size();
        for(auto &m:mp){
            int n = m.second.size();
            sort(m.second.begin(), m.second.end());
            int ans2 = 0;
            // cout<<m.first<<endl;
            for(int i=0; i<n; i++){
                
                int k1 = abs(m.second[i]-m.second[(i-1+n)%n]);
                int k2 = abs(m.second[(i+1)%n]-m.second[i]);
                // cout<<k1<<" "<<k2<<endl;
                if(i==0){
                    k1 = l-k1;
                }
                
                else if(i==n-1){
                    k2 = l-k2;
                }
                int x = ceil(max(k2-1,k1-1)/2.0);
                // cout<<x<<endl;
                ans2 = max(ans2, x);
            }
            ans = min(ans2, ans);
        }
        return ans;
     
        
    }
};