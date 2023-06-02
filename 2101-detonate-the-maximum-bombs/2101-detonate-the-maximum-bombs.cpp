class Solution {
public:
    int dfs(vector<vector<int>> &adj, int u, vector<int> &vis){
        if(vis[u]) return 0;
        vis[u] = 1;
        int ans = 0;
        for(auto &v:adj[u]){
           ans += dfs(adj, v, vis); 
        }
        return 1+ans;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> adj(bombs.size());
        for(int i=0; i<bombs.size(); i++){
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            double r1 = bombs[i][2];
            for(int j=i+1; j<bombs.size(); j++){
                long long x2 = bombs[j][0];
                long long  y2 = bombs[j][1];
                double r2 = bombs[j][2];
            if(sqrt(pow((x2-x1), 2) + pow((y2-y1), 2))<=r2){
               adj[j].push_back(i);
                
            }
            if(sqrt(pow((x2-x1), 2) + pow((y2-y1), 2))<=r1){
                adj[i].push_back(j);
                
            }
            }
        }
        int ans = 0;
       
        for(int i=0; i<bombs.size(); i++){
        vector<int> vis(bombs.size());
           ans = max(ans, dfs(adj, i, vis));
        }
        return ans;
    }
};