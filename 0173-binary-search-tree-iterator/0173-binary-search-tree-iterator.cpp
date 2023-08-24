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
class BSTIterator {
public:
    
    TreeNode* root;
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        this->root = root;
    }
    
    void goLeft( stack<TreeNode*> &st, TreeNode* &root){
        if(!root) return;
        st.push(root);
        goLeft(st, root->left);
    }
    
    int next() {
        goLeft(st, root);
        if(!st.empty()){
            root = st.top();
            st.pop();
            int val = root->val;
            root = root->right;
            return val;
        }
        else {
            return -1;
        }
    }
    
    
    
    bool hasNext() {
        if(root|| !st.empty()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */