/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
      unordered_map<Node* , Node*> mp;
        Node* ptr = head;
        Node* newHead = NULL;
        Node* nptr = NULL;
        while(ptr!=NULL){
            Node* node = new Node(ptr->val);
            node->random = ptr->random;
            if(newHead==NULL){
                newHead = node;
                nptr = node;
            }
            else{
                nptr->next = node;
                nptr = node;
            }
            mp[ptr] = node;
            ptr = ptr->next;
        }
        
      nptr = newHead;
        while(nptr!=NULL){
            nptr->random = mp[nptr->random];
            nptr = nptr->next;
        }
       return newHead; 
        
    }
};