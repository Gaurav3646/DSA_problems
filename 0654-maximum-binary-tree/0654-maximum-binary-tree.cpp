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
    TreeNode* solve(vector<int> &nums, int l, int r){
        if(l>r) return NULL;
            int index = -1;
            int mn = INT_MIN;
        for(int i=l; i<=r; i++){
            if(mn<nums[i]){
               mn = nums[i];
                index = i; 
            }
        }
        TreeNode* node = new TreeNode(nums[index]);
        node->left = solve(nums, l, index-1);
        node->right = solve(nums, index+1, r);
        return node;
        
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        return solve(nums, 0, nums.size()-1);
    }
};