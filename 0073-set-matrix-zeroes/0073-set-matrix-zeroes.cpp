class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
         int c = matrix[0].size();
        int r = matrix.size();
        int col[200]={0};
        int row[200] = {0};
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
               if(matrix[i][j]==0){
                   col[j] = 1;
                   row[i] = 1;
               }
            }
        }
         for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
               if(col[j]||row[i]){
                   matrix[i][j] = 0;
               }
            }
        }
    }
};