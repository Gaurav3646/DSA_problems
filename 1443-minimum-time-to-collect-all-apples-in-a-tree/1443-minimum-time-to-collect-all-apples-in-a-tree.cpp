class Solution {
public:
    pair<int,bool> solve(int u,  vector<vector<int>> &adj, vector<bool> &has, int p){
        
        int ans = 0;
         bool f = false;
        for(auto &v : adj[u]){
            if(v==p) continue;
          pair<int,bool>  p =  solve(v, adj, has, u);
            ans += p.first;
             f |= p.second;  
        }
        if(f==false)
         f = has[u];
       if(f==true)
           ans += 2;
         
//         cout<<"*"<<ans<<" "<<u<<f<<endl;
      return {ans, f};
        
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       pair<int, bool> p = solve(0, adj, hasApple, -1); 
        if(p.second==false) return 0;
        return p.first-2;
    }
};