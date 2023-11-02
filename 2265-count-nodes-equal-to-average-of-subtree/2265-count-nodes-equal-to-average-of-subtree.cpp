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
    pair<int, int> solve(TreeNode* root, int &count){
        if(root==NULL){
            return {0, 0};
        }
        pair<int, int> left = solve(root->left, count);
        pair<int, int> right = solve(root->right, count);
        int sum =  root->val + left.first + right.first;
        int n =  1 + left.second  + right.second;
        
        if((sum/n)== (root->val)){
            count++;
        }
        return {sum, n};
    }
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        pair<int, int> ans = solve(root, count); 
        return count;
    }
};