class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      int rr[8] = {1,1,0,-1,-1,-1,0,1};
      int cc[8] = {0,-1,-1,-1,0,1,1,1};
        int n = grid.size();
        queue<int> q;
      
    vector<vector<int>> vis(n, vector<int>(n , 0));
        // if(i==n-1&&j==n-1) return 1;
        int ans = 0;
        if(grid[0][0]) return -1;
        q.push(0);
        vis[0][0] = 1;
        while(!q.empty()){
            int size = q.size();
            ans++;
            for(int j=0; j<size; j++){
            int x = q.front();
                q.pop();
            int r = x/n;
            int c = x%n;
            if(r==n-1&&c==n-1) return ans;
            for(int i=0; i<8; i++){
                int nr = rr[i]+r;
                int nc = cc[i]+c;
                
                if(min(nr, nc)>=0 && max(nr, nc)<n && !grid[nr][nc] && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push(nr*n+nc);
                }
            }     
        }
    }
        return -1;
        
    }
};