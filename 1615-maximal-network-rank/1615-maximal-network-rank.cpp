class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> rank(n);
        int ans = 0;
        set<pair<int, int>> st;
        for(auto &r: roads){
               rank[r[0]]++;
               rank[r[1]]++;   
            st.insert({r[0], r[1]});
        }
       for(int i=0; i<n; i++){
           for(int j=i+1; j<n; j++){
               int k = rank[i]+rank[j];
               if(st.count({i, j}) || st.count({j,i})){
                   k--;
               }
               ans = max(ans, k);
           }
       }
        
        return ans;
    }
};