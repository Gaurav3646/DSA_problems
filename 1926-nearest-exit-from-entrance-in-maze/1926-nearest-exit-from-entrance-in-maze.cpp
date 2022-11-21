class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), 0));
        maze[entrance[0]][entrance[1]] = '#';
        for(int i=0; i<maze.size(); i++){
            for(int j=0; j<maze[0].size(); j++){
                if((i==0 || j==0 || i==maze.size()-1 || j== maze[0].size()-1) && maze[i][j]=='.'){
                    visited[i][j] = 1;
                    q.push({{i, j}, 0});
                    
                }
            }
        }
        // cout<<q.size()<<endl;
        while(!q.empty()){
            pair<pair<int, int>, int> front = q.front();
            int r = front.first.first;
            int c = front.first.second;
            int d = front.second;
            q.pop();
              int delrow[] = {-1, 0, +1, 0};
              int delcol[] = {0, +1, 0, -1};
            for(int i=0; i<4; i++){
                int nr = r + delrow[i];
                int nc = c + delcol[i];
                if(min(nr, nc)<0 || nr>=maze.size() || nc>=maze[0].size() || visited[nr][nc] || maze[nr][nc]=='+'){
                    continue;
                }
                if(maze[nr][nc]=='#'){
                    return d+1;
                }
                visited[nr][nc] = true;
                q.push({{nr, nc}, d+1});
            }
        }
        return -1;
        
    }
};