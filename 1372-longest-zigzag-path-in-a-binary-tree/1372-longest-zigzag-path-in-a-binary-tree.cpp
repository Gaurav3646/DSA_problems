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
    int maxi = 0;
    int solve(TreeNode* root, int dir){
        if(!root) return 1;
     // cout<<"<"<<endl;
      int left =  solve(root->left, -1);
    // cout<<">"<<endl;
      int right = solve(root->right, 1);
    // cout<<left<<" "<<right<<" "<<dir<<endl;
     if(dir==-1){
       maxi = max(right+1, maxi);
         return right+1;
     }
    else if(dir==1){
        maxi = max(left+1, maxi);
         return left+1; 
    }
    else{
       maxi = max(maxi, (left, right)); 
        return maxi;
    }

        
      
        
    }
    int longestZigZag(TreeNode* root) {
     return  solve(root, 0)-1;
        
        
    }
};