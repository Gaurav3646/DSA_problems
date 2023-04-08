/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> mp;
    void solve(Node* node){
        if(mp.find(node->val)!=mp.end()) return ;
       Node* n = new Node(node->val);
         mp[node->val] = n;
        vector<Node*> &adj = node->neighbors;
        for(int i=0; i<adj.size(); i++){
            cloneGraph(adj[i]);
            // cout<<adj[i]->val<<endl;
            if(mp.find(adj[i]->val)!=mp.end()){
             (n->neighbors).push_back(mp[adj[i]->val]);
            }
        }
      
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
       solve(node);
      return mp[node->val];
    }
};