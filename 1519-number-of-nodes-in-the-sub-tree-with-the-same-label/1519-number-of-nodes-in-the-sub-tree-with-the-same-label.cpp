class Solution {
public:
    
    vector<int> solve(int u, vector<vector<int>>& adj, int p , string &s,  vector<int> &ans){
        
        vector<int> a(26, 0);
        for(auto &v : adj[u]){
            if(v==p) continue;
            vector<int> b = solve(v, adj, u, s, ans);
            for(int i=0; i<26; i++){
                a[i] += b[i];
            }
        }
        ans[u] = ++a[s[u]-'a'];
        return a;
        
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
        vector<int> ans(n);
    vector<int> vect =  solve(0, adj, -1, labels, ans); 
        return ans;
    }
};