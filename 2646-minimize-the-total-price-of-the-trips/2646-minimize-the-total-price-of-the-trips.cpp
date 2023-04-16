class Solution {
public:
    bool isPath(int s, int e, vector<int> &demand,  vector<vector<int>> &tree, int p){
        if(s==e){
          demand[s]++;
            return true;
        }
        for(auto &u:tree[s]){
             if(u==p) continue;
            if(isPath(u, e, demand, tree, s)){
                demand[s]++;
            return true;
            }
        }
        return false;
    }
    pair<int, int> minCost(vector<vector<int>> &tree, int u, int p, vector<int> &demand, vector<int> &price){
              int curr = (price[u]/2)*demand[u];
              int dontCurr = price[u]*demand[u];
        for(auto &v:tree[u]){
            if(v==p) continue;
           pair<int, int>  x = minCost(tree, v, u, demand, price);
            curr += x.second;
            dontCurr += min(x.first, x.second);
            
        }
        return {curr, dontCurr};
    }
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> tree(n);
        for(auto &e:edges){
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        vector<int> demand(n, 0);
        for(auto &t:trips){
            int s = t[0];
            int e = t[1];
            isPath(s, e, demand, tree, -1);
        }
        pair<int, int> mini = minCost(tree, 0, -1, demand, price);
        return min(mini.first, mini.second);
    }
};

