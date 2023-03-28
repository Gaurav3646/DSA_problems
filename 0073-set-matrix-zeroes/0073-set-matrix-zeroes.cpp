class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
         int c = matrix[0].size();
        int r = matrix.size();
         bool firstRow = false; 
        bool firstCol = false;  
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
               if(matrix[i][j]==0){
                   if(i==0) firstRow = true;
                    if(j==0) firstCol = true;
                   matrix[0][j] = 0;
                   matrix[i][0] = 0;
                   
               }
                // cout<<matrix[i][j]<<" ";
            }
            // cout<<endl;
        }
         for(int i=1; i<matrix.size(); i++){
            for(int j=1; j<matrix[0].size(); j++){
               if( matrix[0][j]==0 || matrix[i][0] == 0){
                   matrix[i][j] = 0;
               }
            }
        }
        
       for(int j=0; j<matrix[0].size(); j++){
               if(firstRow){
                   matrix[0][j] = 0;
               }
            }
           for(int i=0; i<matrix.size(); i++){
               if(firstCol){
                   matrix[i][0] = 0;
               }
            
        }
        
    }
};