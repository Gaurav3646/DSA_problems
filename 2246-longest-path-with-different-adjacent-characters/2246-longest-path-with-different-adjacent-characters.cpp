class Solution {
public:
        int maxi = 1;
   pair<int, char> solve(int u, vector<vector<int>>& adj, string &s){
          pair<int, char> ans = {0, '#'};
       for(auto &v : adj[u]){
      pair<int, char> x = solve(v, adj, s);
           if(x.second!=s[u]){
              maxi = max(ans.first+1+x.first,  maxi);
               if(ans.first<x.first)
                   ans = x;
           }
        
       }
       ans.first++;
       ans.second = s[u];
      return ans;
   } 
        
    int longestPath(vector<int>& parent, string s) {
        maxi = 1;
        vector<vector<int>> adj(parent.size());
        for(int i=1; i<parent.size(); i++){
            adj[parent[i]].push_back(i);
        }
        pair<int,char> ans = solve(0, adj, s);
        return maxi;
    }
};