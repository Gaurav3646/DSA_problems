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
    bool solve(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;
        else if((!root && subRoot)||(root && !subRoot)) return false;
       
return solve(root->left, subRoot->left)  && root->val == subRoot->val && solve(root->right, subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    
        if(!root) return false;
        
       return  solve(root, subRoot)||isSubtree(root->left, subRoot)||isSubtree(root->right, subRoot);
        
    }
};