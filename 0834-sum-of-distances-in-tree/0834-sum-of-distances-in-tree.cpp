class Solution {
public:
        void dfs(int root, int pre, vector<vector<int>> &dist, vector<int> &count, vector<int> &res) {
        for (auto i : dist[root]) {
            if (i == pre) continue;
            dfs(i, root, dist, count, res);
            count[root] += count[i];
            res[root] += res[i] + count[i];
        }
    }

    void dfs2(int root, int pre, vector<vector<int>> &dist, vector<int> &count, vector<int> &res) {
        for (auto i : dist[root]) {
            if (i == pre) continue;
            res[i] = res[root] - count[i] + count.size() - count[i];
            dfs2(i, root, dist, count, res);
        }
        
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> dist(n);
        vector<int> count(n, 1);
        vector<int> res(n, 0);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            dist[u].push_back(v);
            dist[v].push_back(u);
          
        }
        dfs(0, -1, dist, count, res);
        dfs2(0, -1, dist, count, res);
        return res;

    }


};