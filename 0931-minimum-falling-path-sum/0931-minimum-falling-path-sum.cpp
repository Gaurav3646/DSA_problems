class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<int> prev(matrix[0].begin(), matrix[0].end());
        for(int i=1; i<matrix.size(); i++){
           vector<int> curr;
            for(int j=0; j<matrix.size(); j++){
                int ans =prev[j];
                if(j>0){
                    ans = min(prev[j-1], ans);
                }
                if(j<matrix.size()-1){
                    ans = min(prev[j+1], ans);
                }
                curr.push_back(ans+matrix[i][j]);
            }
            prev = curr;
        }
        int mini = INT_MAX;
        for(auto &it:prev){
            mini = min(mini, it);
        }
        return mini;
 
    }
};