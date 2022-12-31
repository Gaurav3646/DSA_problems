class Solution {
public:
    int n,m;
    int ans=0;
    void solve(vector<vector<int>> &grid,int i,int j,int cnt)
    {
         if(grid[i][j]==-1)return;
        if(grid[i][j]==2)
        {
            
            if(cnt==-1)
            {
                // cout<<"hi";
                ans++;
                return ;
            }
                return;
    
        }
        grid[i][j]=-1;
         if(i+1<n)
        solve(grid,i+1,j,cnt-1);
         if(i-1>=0)
        solve(grid,i-1,j,cnt-1);
         if(j+1<m)
        solve(grid,i,j+1,cnt-1);
         if(j-1>=0)
        solve(grid,i,j-1,cnt-1);
        grid[i][j]=0;
        return;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)cnt++;
            }
        }
        cout<<cnt;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    
                    solve(grid,i,j,cnt);
                    return ans;
                }
                    
            }
        }
       
        return 0;
        
    }
};