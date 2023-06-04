class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int u, vector<int>& visited){
          visited[u] = 1;
        for(int i=0; i<isConnected[u].size(); i++){
            if( isConnected[u][i] && !visited[i]){
               dfs(isConnected, i, visited); 
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
         vector<int> visited(isConnected.size(), 0);
        int ans = 0;
        for(int i=0; i<isConnected.size(); i++){
            if(!visited[i]){
                dfs(isConnected, i, visited);
                ans++;
            }
        }
        return ans;
    }
};