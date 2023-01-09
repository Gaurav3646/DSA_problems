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
    vector<int> preorderTraversal(TreeNode* root) {
        //morris traversal;
            TreeNode* curr = root;
        vector<int> inorder;
        while(curr){
            if(curr->left==NULL){
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* pred = curr->left;
                while(pred->right &&pred->right!=curr){
                    pred = pred->right;
                }
                if(pred->right==NULL){
                    pred->right = curr;
                     inorder.push_back(curr->val);
                    curr = curr->left;
                    
                }
                else{
                    pred->right =NULL;
                   
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};