class Solution {
public:
//     int solve(string word1, string word2, int i, int j, vector<vector<int>> &dp){
//         if(i>=word2.size()){
//             return word1.size()-j;
//         }
        
//         if(j>=word1.size()){
//             // it means word1 is not converted in word2;
//             return word2.size()-i;
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         int mini = INT_MAX;
//         if(word1[j]==word2[i]){
//           mini =  solve(word1, word2, i+1,j+1, dp);  
//         }
//         else{
//             // insert a character
//             mini = min(mini, 1+solve(word1, word2, i+1, j, dp));
//             // delete a character
//             mini = min(mini, 1+solve(word1, word2, i, j+1, dp));
//             // replace a character
//             mini = min(mini ,1+solve(word1, word2, i+1, j+1, dp));
//         }
//         return dp[i][j] = mini;
//     }
//     int solveTab(string word1, string word2){
//         vector<vector<int>> dp(word2.size()+1, vector<int>(word1.size()+1, 0));
//         // base conditions
//         for(int j=0; j<=word1.size(); j++){
//               dp[word2.size()][j]=word1.size()-j;  
//         }
//         for(int j=0; j<=word2.size(); j++){
//               dp[j][word1.size()]= word2.size()-j;  
//         }
        
        
//         for(int i=word2.size()-1; i>=0; i--){
//             for(int j=word1.size()-1; j>=0; j--){
//                   int mini = INT_MAX;
//         if(word1[j]==word2[i]){
//           mini =  dp[i+1][j+1];  
//         }
//         else{
//             // insert a character
//             mini = min(mini, 1+dp[i+1][j]);
//             // delete a character
//             mini = min(mini, 1+dp[i][j+1]);
//             // replace a character
//             mini = min(mini, 1+dp[i+1][j+1]);
//         }
//         dp[i][j] = mini;
//             }
//         }
//         return dp[0][0];
//     }
    int solveTabOp(string word1, string word2){
        // vector<vector<int>> dp(word2.size()+1, vector<int>(word1.size()+1, 0));
        // reverse the concept
        vector<int> next(word2.size()+1, 0);
        vector<int> curr(word2.size()+1, 0);
        // base conditions
        for(int j=0; j<word2.size(); j++){
              next[j]=word2.size()-j;  
        }
    
        // for(int j=0; j<=word2.size(); j++){
        //       dp[j][word1.size()]= word2.size()-j;  
        // }
        
        
        for(int i=word1.size()-1; i>=0; i--){
            curr[word2.size()] = word1.size()-i;
            for(int j=word2.size()-1; j>=0; j--){
                
                  int mini = INT_MAX;
        if(word2[j]==word1[i]){
          mini =  next[j+1];  
        }
        else{
            // insert a character
            mini = min(mini, 1+next[j]);
            // delete a character
            mini = min(mini, 1+curr[j+1]);
            // replace a character
            mini = min(mini, 1+next[j+1]);
        }
        curr[j] = mini;
            }
            next = curr;
        }
        return next[0];
    }
    int minDistance(string word1, string word2) {
        // vector<vector<int>> dp(word2.size(), vector<int>(word1.size(), -1));
        // return solve(word1, word2, 0, 0, dp);
        // return solveTab(word1, word2);
        return solveTabOp(word1, word2);
    }
};