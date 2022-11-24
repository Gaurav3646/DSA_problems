

class Solution {
public:
    bool solve(vector<vector<char>>& board, int i, int j, string word){
     if(word.length()==0){
            return true;
        }
    if(i<0||i>=board.size()||j<0||j>=board[0].size()|| board[i][j] ==' '||board[i][j]!=word[0]){
        return false;
    }

        word = word.substr(1);
         char c=board[i][j];
            board[i][j]=' ';
        bool ans = false;
           ans |= solve(board, i+1, j, word);
            ans |= solve(board, i-1, j, word);
            ans |= solve(board, i, j+1, word);
            ans |= solve(board, i, j-1, word);
            board[i][j]=c;
        return ans;
}
    bool exist(vector<vector<char>>& board, string word) {
  
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                 if(solve(board, i, j, word)) return true;
            }
        }
      return false;
    }
};