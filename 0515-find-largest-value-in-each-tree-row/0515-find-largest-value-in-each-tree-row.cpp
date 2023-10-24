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
    void solve(TreeNode* root, int level, vector<int> &vect) {
        if(!root) return;
        if(vect.size()<=level){
            vect.push_back(root->val);
            }
        else{
            if(vect[level]<root->val){
                vect[level] = root->val;
                }
            }
        solve(root->left, level+1, vect);
        solve(root->right, level+1, vect);
        }
    vector<int> largestValues(TreeNode* root) {
        vector<int> vect;
        solve(root, 0, vect);
        return vect;
    }
};