class Solution {
public:
    // prerequisities = edges
    // numCourses = N
bool dfs(vector<vector<int>> &adjList, vector<bool> &visited, vector<bool> &dfsVisited, int i){
          visited[i]=true;
          for(int j=0; j<adjList[i].size(); j++){
              if(!visited[adjList[i][j]]){
                   dfsVisited[adjList[i][j]] = true;
                 bool a =  dfs(adjList, visited, dfsVisited, adjList[i][j]); 
                 if(a) return true;
              }
              else{
                  if(dfsVisited[adjList[i][j]]) return true;
              }
          }
    // visited[i]=false;
    dfsVisited[i] = false;
    return false;
   
}
    
    
    bool canFinish(int N, vector<vector<int>>& edges) 
    {
      vector<vector<int>> adjList(N);
     for(int i=0; i<edges.size(); i++)
     {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[v].push_back(u);
      }
         vector<bool> visited(N, false);
        vector<bool> dfsVisited(N, false);
    for(int i=0; i<N; i++){
           if(!visited[i]){
            dfsVisited[i]= true;
              bool ans = dfs(adjList, visited, dfsVisited, i);
            if(ans==true){
                return false;
            }
           }
    }
        return true;
    }
};