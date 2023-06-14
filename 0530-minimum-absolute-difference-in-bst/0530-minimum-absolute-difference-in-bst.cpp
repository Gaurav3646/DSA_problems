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
    int ans = INT_MAX;
    void solve(TreeNode* root,int &x){
        if(!root) return;
        solve(root->left, x);
        if(x!=-1)
        ans = min(ans, abs(x-root->val));
        cout<<x<<" "<<root->val<<endl;
        x = root->val;
        
        solve(root->right, x);
    }
    int getMinimumDifference(TreeNode* root) {
         int x = -1;
        solve(root, x);
        return ans;
    }
};