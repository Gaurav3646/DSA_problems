class Solution {
public:
     vector<vector<int>> ans;
    void dfs(int u, vector<vector<int>> &graph, vector<int> &visited,  vector<int> path){
        visited[u] = 1;
         path.push_back(u);
        if(u==graph.size()-1){
            ans.push_back(path);
        }
        for(auto &v : graph[u]){
            if(!visited[v]){
                dfs(v, graph, visited, path);
            }
        }
     path.pop_back();
        visited[u] = 0;
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> visited(graph.size());
        
        dfs(0, graph, visited,{});

     return ans;
    }
};