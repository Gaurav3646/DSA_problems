class Solution {
public:
    bool dfs( vector<vector<int>> &adj, int u, vector<int> &visited){
        for(auto &v :adj[u]){
            if(visited[v]==-1){
                visited[v]= 1-visited[u];
                // cout<<v<<" "<<visited[v]<<endl;
            if(dfs(adj, v, visited)==false) return false;
            }
            else if(visited[v]==visited[u]){
                // cout<<v<<" "<<visited[v]<<visited[u]<<u<<endl;
                // cout<<"*"<<endl;
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(int i=0; i<dislikes.size(); i++){
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n+1, -1);
        
         for(int i=1; i<=n; i++){
             if(visited[i]==-1){
              visited[i] = 1;
                 // cout<<i<<"*"<<endl;
              if(dfs(adj, i, visited)==false) return false;
             }
         }
        return true;
    }
};