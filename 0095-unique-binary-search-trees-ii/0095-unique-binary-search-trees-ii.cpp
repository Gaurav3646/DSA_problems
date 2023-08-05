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
    vector<TreeNode*> solve(int i, int n){
       if(i>n) return {NULL};
        vector<TreeNode*> NodeList;
      for(int j=i; j<=n; j++){
          vector<TreeNode*> left = solve(i, j-1);
          vector<TreeNode*> right = solve(j+1, n);
          
          for(int l=0; l<left.size(); l++){
              for(int r=0; r<right.size(); r++){
                  TreeNode* node = new TreeNode(j);
                  node->left = left[l];
                  node->right = right[r];
                  NodeList.push_back(node);
              }
          }
      }
        return NodeList;
    }
    vector<TreeNode*> generateTrees(int n) {
         return solve(1, n);
    }
};