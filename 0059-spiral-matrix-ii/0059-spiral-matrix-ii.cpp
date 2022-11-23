class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        // I have taken four variable here 
        // you can understand variable by it's name. 
        int firstRow = 0;
        int firstCol = 0;
        int lastRow = n-1;
        int lastCol = n-1;
        
        
        // val is value for the particular matrix[row][col]
        // I have taken val = 0 since in further code I am using preincrament operator 
        int val = 0;
        
        
        // matrix intialization
       vector<vector<int>> matrix(n, vector<int>(n));
        
        
        while(true){
            //  traversing first row and assigning values to it
            for(int i=firstCol; i<=lastCol; i++){

                matrix[firstRow][i]= ++val;
            }
            
            // if both row are same position then break;
              if(firstRow==lastRow) break;
            firstRow++;
            
            //  traversing last Column and assigning values to it
            for(int i=firstRow; i<=lastRow; i++){
        
                 matrix[i][lastCol]= ++val;
            }
            
            // if both column are same position then break;
            if(firstCol==lastCol) break;
            lastCol--;
            
            //  traversing last Row and assigning values to it
            for(int i=lastCol; i>=firstCol; i--){
    
                 matrix[lastRow][i]= ++val;
            }
            
            // if both row are same position then break;
             if(firstRow==lastRow) break;
            lastRow--;
            
            //  traversing first column and assigning values to it
            for(int i=lastRow; i>=firstRow; i--){

                 matrix[i][firstCol]= ++val;
            }
            
            // if both column are same position then break;
             if(firstCol==lastCol) break;
           firstCol++;
        }
        
        return matrix;
    }
};
// <-- thank you -->