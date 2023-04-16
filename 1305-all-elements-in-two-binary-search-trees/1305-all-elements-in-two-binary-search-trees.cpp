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
void leftPush(TreeNode* r, stack<TreeNode*> &s){
    while(r!=NULL){
      s.push(r);
        r = r->left;
    }
}
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
            stack<TreeNode*> s1, s2;
         leftPush(root1, s1);
         leftPush(root2, s2);
        vector<int> ans;
        while(!s1.empty() || !s2.empty()){
            stack<TreeNode*> &s = s1.empty() ? s2: s2.empty()? s1:
            s1.top()->val < s2.top()->val?s1:s2;
            auto min = s.top(); s.pop();
            ans.push_back(min->val);
            leftPush(min->right, s);
            
        }
        return ans;
    }
};