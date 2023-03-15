class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int> st;
        for(auto &n:nums){
            st[n]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto &s:st){
            pq.push({s.second, s.first});
        }
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
         return ans;   
        }
};