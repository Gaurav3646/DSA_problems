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
    int solve(TreeNode* root, int mini, int maxi){
       if(root==NULL) return INT_MIN;
        if(root->val>maxi){
            maxi = root->val;
        }
        else if(root->val<mini){
            mini = root->val;
        }
          int ans = maxi-mini;
          ans = max(ans, solve(root->left, mini, maxi));
          ans = max(ans, solve(root->right, mini, maxi));
        return ans;
    }
    int maxAncestorDiff(TreeNode* root) {
        vector<int> ancestor;
        // ancestor.push_back(root->val);
        int min = root->val;
        int max = root->val;
      return solve(root, min, max);
    }
};