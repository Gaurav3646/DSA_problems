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
        // if(l==r){
        //    TreeNode* node = new TreeNode(nums[l]);
        //  return node;
        // }
        int mid = l+(r-l)/2;
        // cout<<l<<mid<<r<<endl;
      TreeNode* left =  solve(nums, l, mid-1);
      TreeNode* right = solve(nums, mid+1, r);
        TreeNode* node = new TreeNode(nums[mid], left, right);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return solve(nums, 0, nums.size()-1);
    }
};