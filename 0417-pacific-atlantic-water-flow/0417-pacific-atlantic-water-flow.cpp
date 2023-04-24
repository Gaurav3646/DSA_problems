class Solution {
public:
  
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector pac(n, vector<int>(m, 0));
         vector atl(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0||j==0||i==n-1 || j==m-1){
                if(i==0||j==0) pac[i][j] = 1;
                if(i==n-1||j==m-1) atl[i][j] = 1;
                q.push({i, j});
                
                }
            }
        }
        
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int d[4] = {-1, 0, +1, 0};
            for(int i=0; i<4; i++){
                 int ni = p.first+d[i];
                    int nj = p.second+d[3-i];
                if(ni>=0&&ni<n && nj>=0&&nj<m && heights[ni][nj]>=heights[p.first][p.second]){
                    if(pac[p.first][p.second] &&atl[p.first][p.second]){       if(!(pac[ni][nj]&&atl[ni][nj])){
                        pac[ni][nj] = 1;
                         atl[ni][nj] = 1;
                           q.push({ni, nj});  
                        }
                                                                    
                    }
                   else if(pac[p.first][p.second]){
                        if(!pac[ni][nj]){
                            pac[ni][nj] = 1;
                            q.push({ni, nj});
                        }
                    }
                   else if(atl[p.first][p.second]){
                        if(!atl[ni][nj]){
                            atl[ni][nj] = 1;
                            q.push({ni, nj});
                        }
                    }
                    
                }
                   
                
            }
        }
        vector<vector<int>> ans;
       for(int i=0; i<n; i++){
           for(int j=0; j<m; j++){
               if(pac[i][j]&&atl[i][j]) ans.push_back({i, j});
           }
       }
        return ans;
        
    }
};