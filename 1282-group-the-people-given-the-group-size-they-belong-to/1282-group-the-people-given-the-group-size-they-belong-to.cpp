class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& group) {
       unordered_map<int,vector<int>> mp;
        int i=0;
        for(auto &g:group){
            mp[g].push_back(i++);
        }
        vector<vector<int>> ans;
        for(auto &m:mp){
             vector<int> &vect = m.second;
            vector<int> x;
            for(int i=0; i<vect.size(); i++){
                x.push_back(vect[i]);
                if((i+1)%m.first==0){
                    ans.push_back(x);
                    x.clear();
                }
            }
        }
        return ans;
    }
};