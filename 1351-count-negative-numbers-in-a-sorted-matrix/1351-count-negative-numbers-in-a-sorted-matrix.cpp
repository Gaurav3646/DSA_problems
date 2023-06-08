class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        int  r=grid.size()-1;
        int  c=0;
        while(r>=0 && c<grid[0].size()){
            if(grid[r][c]>=0) c++;
            else{
             cnt +=  grid[r].size()-c;
                r--;
            }
                
            
        }
        return cnt;
    }
};