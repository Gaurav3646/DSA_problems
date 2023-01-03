class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
       vector<vector<int>> minDist(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        set<pair<int,pair<int, int>>> st;
        st.insert({0, {0, 0}});
        minDist[0][0] = 0;
        while(!st.empty()){
           auto p  = *(st.begin());
            st.erase(st.begin());
            int dist = p.first;
            int r = p.second.first;
            int c = p.second.second;
         int row[] = {0,0,-1, +1};
         int col[] = {-1,+1, 0, 0};
         // int ans =INT_MAX;
         for(int i=0; i<4; i++){
            int nr = r + row[i];
            int nc = c + col[i];
            if(nr>=grid.size() || nc>=grid[0].size() || min(nr, nc)<0){
             continue;
            }
            int maxi = max(dist,abs(grid[nr][nc]-grid[r][c]));
             if(maxi<minDist[nr][nc]){
                  if(minDist[nr][nc]!=INT_MAX){
                      st.erase({minDist[nr][nc], {nr, nc}});
                  }
                 // cout<<maxi<<endl;
                 minDist[nr][nc] = maxi;
                 st.insert({maxi, {nr, nc}});
             }
             
        }
            
      
        }
      // for(auto & vect : minDist){
      //       for(auto &el : vect){
      //           cout<<el<<" ";
      //       }
      //       cout<<endl;
      // }
        return minDist[grid.size()-1][grid[0].size()-1];
    }
};