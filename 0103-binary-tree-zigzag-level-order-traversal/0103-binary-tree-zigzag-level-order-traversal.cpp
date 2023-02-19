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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool l_to_r = true;
        while(!q.empty()){
            
            int size = q.size();
            vector<int> vect(size);
          if(l_to_r){
              for(int i=0; i<size; i++){
                  TreeNode* curr= q.front();
                  
                 vect[i] = curr->val;
                   q.pop();
                  if(curr->left)
                      q.push(curr->left);
                  if(curr->right)
                      q.push(curr->right);
                  
              }
          }
            else{
                for(int i=size-1; i>=0; i--){
                  TreeNode* curr= q.front();
                  
                  vect[i] = curr->val;
                   q.pop();
                  if(curr->left)
                      q.push(curr->left);
                  if(curr->right)
                      q.push(curr->right);
                  
              }  
            }
            ans.push_back(vect);
            l_to_r = !l_to_r;
        }
        return ans;
    }
};