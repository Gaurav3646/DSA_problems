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
      int solve(TreeNode* root, int low, int high){
          if(root==NULL) return 0;
          int left = 0;
          int right = 0;
           if(root->val>=low)
        left =  solve(root->left, low, high);
          cout<<root->val<<endl;
          if(root->val>high) return left;
           if(root->val>=low) 
         return left + root->val + solve(root->right, low, high);
         return left + solve(root->right, low, high);
         
      }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        ans = solve(root, low, high);
        return ans;
    }
};