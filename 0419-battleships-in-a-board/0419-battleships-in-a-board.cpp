class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        for(int i=0; i<board.size(); i++){
            
            for(int j=0; j<board[0].size(); j++){
                 int c = 0;
                  if(i!=0 && board[i-1][j]=='X')
                       c= 1;
                   if(j!=0 && board[i][j-1]=='X')
                       c= 1;
                // cout<<c<<" ";
                     if(c!=1 && board[i][j]=='X')
                         ans++;
                  
                    
            }
            // cout<<endl;
        }
        return ans;
    }
};