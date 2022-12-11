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
    int maxi = INT_MIN;
    int solve(TreeNode* root){
        if(!root) return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        int temp = max(left,right);
        
        maxi = max(maxi, root->val+left+right);
        maxi = max(maxi, root->val + temp);
        maxi = max(maxi, root->val);
        if(temp<0) return root->val;
        else  return root->val +temp;
//        if((root->val+temp)>0){
//           if(maxi<(root->val+temp)){
//               maxi = root->val+temp;
              
//           }
//            return root->val+temp;
       
//        }
//         else{
//             if(maxi<root->val){
//                 maxi = root->val;
//             }
//            return 0;
//         }
          
        
    }
    int maxPathSum(TreeNode* root) {
        maxi = INT_MIN;
        int ans = solve(root);
        return maxi;
    }
};