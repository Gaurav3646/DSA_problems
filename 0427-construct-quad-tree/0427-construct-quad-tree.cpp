class Solution {
public:

    Node * solve(int x1,int y1,int x2,int y2,vector<vector<int>>& grid)
    {
        int one=0;
        int zero=0,val,n=x2-x1+1,half=n/2;

        if(x1==x2||y1==y2)
            return new Node(grid[x1][y1],1,NULL,NULL,NULL,NULL);
        for(int i=x1;i<=x2;i++)
        {
            for(int j=y1;j<=y2;j++)
            {
                if(grid[i][j]==0) zero++;
                if(grid[i][j]==1)one++;
            }
        }
        if((zero==n*n) ||(one==n*n))
        {
            if(zero!=0) val=0;
            if(one!=0) val=1;
            return new Node(val,1,NULL,NULL,NULL,NULL);
        }
        else
return new Node(1,0,solve(x1,y1,x1+half-1,y1+half-1,grid),solve(x1,y1+half,x1+half-1,y1+n-1,grid),solve(x1+half,y1,x1+n-1,y1+half-1,grid),solve(x1+half,y1+half,x1+n-1,y1+n-1,grid));
        
    }
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        return solve(0,0,n-1,n-1,grid);
    }
};