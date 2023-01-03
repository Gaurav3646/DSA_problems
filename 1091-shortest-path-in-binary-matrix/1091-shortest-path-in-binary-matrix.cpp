class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> minDist(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        if(grid[0][0]==1) return -1;
        minDist[0][0] = 1;
        set<pair<int,pair<int, int>>> st;
        st.insert({1, {0, 0}});
        while(!st.empty()){
           auto p  = *(st.begin());
            st.erase(st.begin());
            int dist = p.first;
            int r = p.second.first;
            int c = p.second.second;
         int row[] = {0,0, +1, +1, +1, -1, -1, -1};
         int col[] = {-1,+1, 0, -1, +1, 0, -1, +1};
         int ans =INT_MAX;
         for(int i=0; i<8; i++){
            int nr = r + row[i];
            int nc = c + col[i];
            if(nr>=grid.size() || nc>=grid[0].size() || min(nr, nc)<0 || grid[nr][nc]){
             continue;
            }
            
             if(dist+1<minDist[nr][nc]){
                  if(minDist[nr][nc]!=INT_MAX){
                      st.erase({minDist[nr][nc], {nr, nc}});
                  }
                 minDist[nr][nc] = dist+1;
                 st.insert({minDist[nr][nc], {nr, nc}});
             }
             
        }
            }
        if(minDist[grid.size()-1][grid[0].size()-1] == INT_MAX) return -1;
        return minDist[grid.size()-1][grid[0].size()-1];
        
    }
};