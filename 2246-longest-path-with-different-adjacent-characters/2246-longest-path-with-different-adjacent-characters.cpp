class Solution {
public:
        int maxi = 0;
   pair<int, char> solve(int u, vector<vector<int>>& adj, int parent, string &s){
        // if(!root) return 0;
          pair<int, char> ans = {0, '#'};
       for(auto &v : adj[u]){
           if(v==parent) continue;
      pair<int, char> x = solve(v, adj, u, s);
           if(x.second!=s[u]){
              maxi = max(ans.first+1+x.first,  maxi);
               if(ans.first<x.first)
                   ans = x;
           }
        // if(root->val==left && root->val==right)
        //       maxi = max(maxi, 1);
        // else if(root->val==left.second){
        //       maxi = max(maxi, 1+right.first);  
        //     }
        // else if(root->val==right.second){
        //       maxi = max(maxi, 1+left.first);   
        //     }
        //  else{
        //  maxi = max(maxi, temp); 
        //  } 
       }
       maxi = max(maxi, 1);
       // cout<<maxi<<endl;
       ans.first++;
       ans.second = s[u];
      return ans;
   } 
        
    int longestPath(vector<int>& parent, string s) {
        maxi = INT_MIN;
        vector<vector<int>> adj(parent.size());
        for(int i=1; i<parent.size(); i++){
            
            adj[parent[i]].push_back(i);
        }
        pair<int,char> ans = solve(0, adj, -1, s);
        return maxi;
    }
};