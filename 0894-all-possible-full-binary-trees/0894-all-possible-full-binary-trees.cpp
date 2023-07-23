/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   vector<TreeNode*> solve(int n, vector<vector<TreeNode*>> &dp){
        if(n==1){
            TreeNode* node = new TreeNode();
            return {node}; 
        }
        if(dp[n].size()){
           return dp[n];
        }
        vector<TreeNode*> vect;
       for(int p=1; p<n; p+=2){
          vector<TreeNode*> leftSub = solve(p, dp);
          vector<TreeNode*> rightSub = solve(n-p-1, dp);
           
           for(int i=0; i<leftSub.size(); i++){
               for(int j=0; j<rightSub.size(); j++){
                  TreeNode* node = new TreeNode();
           node->left = leftSub[i];
           node->right = rightSub[j];
                   dp[n].push_back(node);
                   vect.push_back(node);
               }
           }
           
       }
       return  vect;  
    }
    vector<TreeNode*> allPossibleFBT(int n) {
      
        vector<vector<TreeNode*>> dp(n+1);
       return solve(n, dp);
    }
};