class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
          priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<vector<int>> adj[n+1];
        for(int i=0; i<times.size(); i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        vector<bool> vis(n + 1, false);
        vector<int> dist(n+1, INT_MAX);
        pq.push({0, k});
        dist[k] =0;
        while(!pq.empty()){
            pair<int, int> p = pq.top();
            int u = p.second;
            int w = p.first;
            
            pq.pop();
            if(vis[u]) continue;
            vis[u]=true;
            for(auto it: adj[u]){
                if(w+it[1]<=dist[it[0]]){
                    dist[it[0]] = w+it[1];
                    pq.push({dist[it[0]], it[0]});
                }
            }
            
        }
        int mn = INT_MIN;
        for(int i=1; i<=n; i++){
            mn = max(mn, dist[i]);
        }
        if(mn==INT_MAX) return -1;
        return mn;
    }
};