class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
          unordered_map<string, vector<int>> mp;
        for(int i=0; i<strs.size(); i++){
           string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(i);
        }
        vector<vector<string>> myAns;
        for(auto &list: mp){
             vector<string> ans;
            for(auto i : list.second){
                ans.push_back(strs[i]);
            }
            myAns.push_back(ans);
        }
        return myAns;
    }
};