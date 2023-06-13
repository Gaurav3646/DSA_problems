class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mp;
      for(int i=0; i<grid.size(); i++){
          vector<int> vect;
          for(int j=0; j<grid[0].size(); j++){
              vect.push_back(grid[i][j]);
          }
          mp[vect]++;
      }
    
   
    
    int ans = 0;
    for(int i=0; i<grid.size(); i++){
          vector<int> vect;
          for(int j=0; j<grid[0].size(); j++){
              vect.push_back(grid[j][i]);
          }
          if(mp.find(vect)!=mp.end()) ans += mp[vect];
      }
    
return ans;
    }
};