class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int u, vector<int> &visited){
        visited[u] = 1;
        bool x = true;
        for(auto v: graph[u]){
            if(!visited[v]){
                x &= dfs(graph, v, visited);
            }
            else if(visited[v]==1){
               x = false;
            }
        }
      if(x==true)
        visited[u] = 2;
        return x;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // vector<bool> ans(graph.size());
        vector<int> visited(graph.size(), 0);
        for(int i=0; i<graph.size(); i++){
            if(!visited[i]){
               bool u = dfs(graph, i, visited);
            }
        }
        vector<int> safe;
        for(int i=0; i<visited.size(); i++){
            if(visited[i]==2){
                safe.push_back(i);
            }
        }
       return safe;
    }
};