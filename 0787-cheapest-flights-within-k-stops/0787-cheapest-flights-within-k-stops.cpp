class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dist, int k) {
        vector<vector<pair<int, int>>> cities(n);
        for(int i=0; i<flights.size(); i++){
            int from = flights[i][0];
            int to = flights[i][1];
            int price = flights[i][2];
            cities[from].push_back({to, price});
        }
        set<pair<int, pair<int, int>>> st;
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;
        st.insert({0, {src, 0}});
        while(!st.empty()){
            auto tp = *(st.begin());
            int stops = tp.first;
            int cst = tp.second.second;
            int from = tp.second.first;
            st.erase(st.begin());
            if(stops>k) continue;
            for(auto &to : cities[from]){
                if(cst+to.second<cost[to.first]){
                  if(cost[to.first]!=INT_MAX){
                      st.erase({stops+1, {to.first, cost[to.first]}});
                  }
                    cost[to.first] = cst+to.second;
                    st.insert({stops+1, {to.first, cost[to.first]}});
                }
            }
        }
        return cost[dist]==INT_MAX?-1:cost[dist];
    }
};