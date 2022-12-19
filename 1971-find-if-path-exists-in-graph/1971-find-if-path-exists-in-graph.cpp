class Solution {
public:
    bool dfs(vector<vector<int>> &adj, int u,int &x, vector<bool> &visited){
        
           visited[u] = true;
        if(visited[x]){
            return true;
        }
        bool ans = false;
        for(auto &v: adj[u]){
            if(!visited[v]){
              ans |= dfs(adj, v, x, visited);
            }
        }
        return ans;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++){
           int u = edges[i][0];
           int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        return dfs(adj, source, destination, visited);
    }
};