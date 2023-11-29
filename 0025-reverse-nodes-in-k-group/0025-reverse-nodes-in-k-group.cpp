/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;
        ListNode* ptr = head;
        ListNode* node = head;
        int i;
        for( i=0; i<k &&node; i++){
            node = node->next;
        }
        if(i!=k){
            return head;
        }
        ListNode* prev = NULL;
       while(ptr!=node){
          ListNode* temp = ptr->next;
           ptr->next = prev;
           prev = ptr;
           ptr = temp;
           
       }
        head->next = reverseKGroup(node, k);
        return  prev;
        
    }
};