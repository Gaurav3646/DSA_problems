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
   
void solve(TreeNode* root,vector<pair<double, int>> &ans, int i=0){
        if(!root) return ;
    
    if(i>=ans.size()){
        ans.push_back({root->val, 1});
    }
    else{
        ans[i] = {ans[i].first+root->val, ans[i].second+1};    
    }
        solve(root->left, ans, i+1);
        solve(root->right, ans, i+1);
        
    }
    vector<double> averageOfLevels(TreeNode* root) {
         vector<pair<double, int>> ans;
        solve(root, ans);
      vector<double> newAns;
        for(auto &it: ans){
           newAns.push_back((it.first/it.second));
        }
        
        return newAns;
    }
};