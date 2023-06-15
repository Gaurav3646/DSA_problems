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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = root->val;
        int level = 1;
        int l = 0;
        while(!q.empty()){
            int sz = q.size();
            int x= 0;
            l += 1;
            for(int i=0; i<sz; i++){
            int f = q.front()->val;
                 x += f;
               
                if(q.front()->left)
                q.push(q.front()->left);
                if(q.front()->right)
                q.push(q.front()->right);
                 q.pop();
            }
           if(ans<x){
               cout<<x<<endl;
               ans = x;
               level = l;
           }
        }
        return level;
    }
};