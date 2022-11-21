class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int u, vector<bool> &visited, vector<bool> &ans){
        visited[u] = true;
        bool x =true;
        for(auto v: graph[u]){
            if(!visited[v]){
                x &= dfs(graph, v, visited, ans);
            }
            else{
               x &= ans[v];
            }
        }
        ans[u] = x;
        return x;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> ans(graph.size());
        vector<bool> visited(graph.size(), false);
        for(int i=0; i<graph.size(); i++){
            if(!visited[i]){
               bool u = dfs(graph, i, visited, ans);
            }
        }
        vector<int> safe;
        for(int i=0; i<ans.size(); i++){
            if(ans[i]==true){
                safe.push_back(i);
            }
        }
       return safe;
    }
};