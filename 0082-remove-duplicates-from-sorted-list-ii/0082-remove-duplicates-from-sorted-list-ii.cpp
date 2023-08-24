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
    ListNode* deleteDuplicates(ListNode* head) {
      head = new ListNode(-101, head);
     ListNode* prev = head;
    
        while(prev){
        ListNode* ptr = prev->next;
            bool f = false;
            while(ptr && ptr->next && ptr->val ==ptr->next->val){
                ptr = ptr->next;
                f = true;
            }
            if(f){ ptr = ptr->next;
            prev->next = ptr;
                 }
            else{
                prev = prev->next;
            }  
        
        }
        return head->next;
        
    
    }
};