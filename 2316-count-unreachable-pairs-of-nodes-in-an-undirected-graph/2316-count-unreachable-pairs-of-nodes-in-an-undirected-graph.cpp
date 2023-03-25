class Solution {
public:
    void dfs(vector<vector<int>> &adj, int root, vector<int> &visited, int &count){
        if(visited[root]) return ;
        count++;
        visited[root] =1 ;
        for(auto &v: adj[root]){
            dfs(adj, v, visited, count);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n);
         vector<long long> vect;
        for(int i=0; i<n; i++){
            int count = 0;
           dfs(adj, i, visited, count);
            // cout<<count<<endl;
            vect.push_back(count);
            
        }
        long long sum = 0;
        for(auto &c:vect){
          sum += c;  
        }
        // cout<<sum<<endl;
        long long ans=0;
        for(auto &c : vect){
            sum -= c;
            ans += sum*c;
        }
        return ans;
    }
};