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
    
    unordered_map<int, vector<pair<vector<int>, int>>> mp;
    vector<TreeNode*> ans;
    bool isSame(vector<int> &x, vector<int> &y){
        if(x.size()!=y.size())return false;
        for(int i=0; i<x.size(); i++){
            if(x[i]!=y[i]) return false;
        }
        return true;
    }
      int dublicate(int z, vector<int> &l){
          for(auto &vect: mp[z]){
              if(isSame(vect.first, l)) return ++vect.second;
          }
          return 1;
      }
        vector<int> solve(TreeNode* root){
        if(!root) return {201};
        vector<int> l = solve(root->left);
        vector<int> r = solve(root->right);
      
        for(int i=0; i<r.size(); i++){
            l.push_back(r[i]);
        }
       l.push_back(root->val);
        if(mp.find(root->val)!=mp.end()){
            int d =dublicate(root->val, l);
         if(d==2){
           ans.push_back(root);  
         }
         else if(d==1) {
            mp[root->val].push_back({l, 1}); 
         }
        }
         else{
             mp[root->val].push_back({l, 1});
         }
       
        return l;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<int> v = solve(root);
        return ans;
    }
};