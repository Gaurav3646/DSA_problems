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
    unordered_map<int, int> mp;
    int solve(TreeNode* root){
        if(!root) return 0;
       int x = root->val + solve(root->left)+solve(root->right);
        mp[x]++;
        return x;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        mp.clear();
      solve(root);
      int max = 0;
        vector<int> ans;
        for(auto &m: mp){
            if(max==m.second){
                ans.push_back(m.first);
            }
            else if(max<m.second){
                max = m.second;
                ans.clear();
                ans.push_back(m.first);
            }
        }
        
        
       return ans; 
        
    }
};