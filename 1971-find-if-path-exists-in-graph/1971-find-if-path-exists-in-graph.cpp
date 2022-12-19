class Solution {
public:
   void dfs(vector<vector<int>> &adj, int u,int &x, vector<bool> &visited){
        
           visited[u] = true;
        if(visited[x]){
            return;
        }
        // bool ans = false;
        for(auto &v: adj[u]){
            if(!visited[v]){
              dfs(adj, v, x, visited);
            }
        }
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
      dfs(adj, source, destination, visited);
        return visited[destination];
    }
};