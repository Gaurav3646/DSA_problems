class Solution {
public:
     bool expand(vector<vector<int>>& A, int i, int j, int cl) {
    if (min(i, j) < 0 || max(i, j) == A.size())
        return false;
    A[i][j] = A[i][j] == 0 ? cl + 1 : A[i][j];
    return A[i][j] == 1;
   }  
    void solve(vector<vector<int>>& grid, int i, int j){
        if(i>=grid.size()||j>=grid[0].size()||grid[i][j]==0||grid[i][j]==2){
            return ;
        }
        grid[i][j] = 2;
 
      solve(grid, i+1, j);
      solve(grid, i-1, j);
      solve(grid, i, j-1);
      solve(grid, i, j+1);
    }
  pair<int, int> find(vector<vector<int>>& grid) {
         for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                  return {i, j};
                  
                } 
            }
        }
      return {-1, -1};
  }
    int shortestBridge(vector<vector<int>>& grid) {
       pair<int, int> p = find(grid);
        solve(grid, p.first, p.second);
    int cl = 2;
        while(cl){
            for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                 if(grid[i][j]==cl && ((expand(grid, i - 1, j, cl) || expand(grid, i, j - 1, cl) || expand(grid, i + 1, j, cl) || expand(grid, i, j + 1, cl))))
                     return cl-2;
            }
        }
            cl++;
        }
      return -1;
    }
};