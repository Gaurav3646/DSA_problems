class Solution {
public:
     
       
    bool isValidSudoku(vector<vector<char>>& board) {
          int used1[9][9] = {0};
          int used2[9][9] = {0};
         int used3[9][9] = {0};
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    int x = board[i][j]-'1';
                    int n = j- j%3;
                    int m = i- i%3;
                    int r = x/3;
                    int c = x%3;
                    // cout<<used3[m+r][n+c]<<endl;
                    if(used1[i][x] || used2[x][j] || used3[m+r][n+c]) return false;
                    
                    used1[i][x] = 1;
                    used2[x][j] = 1;
                    used3[m+r][n+c] = 1;
                }
            }
           
        }
         return true;
    }
};