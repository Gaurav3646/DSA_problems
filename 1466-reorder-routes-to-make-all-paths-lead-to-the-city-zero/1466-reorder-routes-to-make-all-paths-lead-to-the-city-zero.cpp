class Solution {
public:
    int ans = 0;
    void solve(vector<vector<int>> &adjCh, vector<vector<int>> &adjPar, int root, vector<int> &visited){
       
        for(auto &ch:adjCh[root]){
             if(!visited[ch]){
                 ans++;
                 // cout<<ch<<endl;
                 visited[ch]=1;
                 solve(adjCh, adjPar, ch, visited);
             }
        }
         for(auto &par:adjPar[root]){
            if(!visited[par]){
                // cout<<par<<endl;
                visited[par]=1;
                 solve(adjCh, adjPar, par, visited);
             }
        }
        
    }
    int minReorder(int n, vector<vector<int>>& con) {
        vector<vector<int>> adjCh(n);
         vector<vector<int>> adjPar(n);
        for(int i=0; i<con.size(); i++){
           int u = con[i][0];
            int v = con[i][1];
            adjCh[u].push_back(v);
            adjPar[v].push_back(u);
        }
        vector<int> visited(n);
        visited[0] =1;
        solve(adjCh, adjPar, 0, visited);
        return ans;
    }
};