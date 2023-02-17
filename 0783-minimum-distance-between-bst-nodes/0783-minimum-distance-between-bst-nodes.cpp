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
    int solve(TreeNode*  root, int &x){
        if(!root) return INT_MAX;
        int ans =INT_MAX;
       int left = solve(root->left, x);
        if(x!=-1)
        ans = min(ans, root->val-x);
        x = root->val;
       int right = solve(root->right, x);
        return min(left, min(ans, right));
        
    }
    int minDiffInBST(TreeNode* root) {
        int x = -1;
      return solve(root, x); 
    }
};