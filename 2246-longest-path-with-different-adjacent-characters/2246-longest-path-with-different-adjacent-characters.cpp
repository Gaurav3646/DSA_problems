class Solution {
public:
//         int maxi = 1;
//    pair<int, char> solve(int u, vector<vector<int>>& adj, string &s){
//           pair<int, char> ans = {0, '#'};
//        for(auto &v : adj[u]){
//       pair<int, char> x = solve(v, adj, s);
//            if(x.second!=s[u]){
//               maxi = max(ans.first+1+x.first,  maxi);
//                if(ans.first<x.first)
//                    ans = x;
//            }
        
//        }
//        ans.first++;
//        ans.second = s[u];
//       return ans;
//    } 
            int maxi = 1;
   int solve(int u, vector<vector<int>>& adj, string &s){
          int ans = 0;
       for(auto &v : adj[u]){
     int x = solve(v, adj, s);
           if(s[v]!=s[u]){
              maxi = max(ans+1+x,  maxi);
               if(ans<x)
                 ans = x;
           }
       }
       ans++;
        maxi = max(maxi, 1);
      return ans;
   } 
     
        
    int longestPath(vector<int>& parent, string s) {
        maxi = 1;
        vector<vector<int>> adj(parent.size());
        for(int i=1; i<parent.size(); i++){
            adj[parent[i]].push_back(i);
        }
        int ans = solve(0, adj, s);
        return maxi;
    }
};