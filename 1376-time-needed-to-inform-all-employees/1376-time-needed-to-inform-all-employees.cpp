class Solution {
public:
  int  dfs(vector<vector<int>>& child, vector<int>& informTime, int r){
      int maxi  = 0 ;
       for(auto &ch:child[r]){
         maxi = max(maxi, dfs(child, informTime, ch));
       }
      return maxi+informTime[r];
      
  }
    int numOfMinutes(int n, int h, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> child(n);
        
        for(int i=0; i<n; i++){
            if(manager[i]==-1) continue;
        
            child[manager[i]].push_back(i);
        }
       return dfs(child, informTime, h);
        
    }
};