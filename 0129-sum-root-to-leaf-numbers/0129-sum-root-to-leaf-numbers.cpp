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
    long long totalSum = 0;
   void solve(TreeNode* root, int pSum=0){
       if(!root){
           return;
       }
       pSum = pSum*10 + root->val;
       solve(root->left, pSum);
       solve(root->right, pSum);
       if(root->left ==NULL && root->right==NULL)
         totalSum += pSum;
   }
    int sumNumbers(TreeNode* root) {
       solve(root);
        return totalSum;
    }
};