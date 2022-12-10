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
    long long getSum(TreeNode* root){
        if(root==NULL) return 0;
        return  root->val + getSum(root->left) + getSum(root->right);
    }
     long long solve(TreeNode* root, long long &ans, long long &sum){
         if(root==NULL)
             return 0;
         long long  subSum = root->val + solve(root->left, ans, sum) + solve(root->right, ans, sum);
         ans = max(ans, subSum*(sum-subSum));
         return subSum;
     }
    int maxProduct(TreeNode* root) {
        long long totalSum = getSum(root);
        long long  ans = INT_MIN;
       long long x = solve(root, ans , totalSum);
         // ans = INT_MAX;
        long long mod = 1e9+7;
        ans =  ans%mod;
        return ans;
    }
};