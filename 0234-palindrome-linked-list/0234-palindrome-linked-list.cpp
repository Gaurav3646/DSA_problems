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
    bool isPalindrome(ListNode* head) {
      ListNode* fast= head;
        ListNode* slow = head;
         ListNode* prev = NULL;
        while(fast!=NULL&&fast->next!=NULL){
            fast = fast->next->next;
           ListNode* temp = slow;
            slow = slow->next; 
            temp->next = prev;
            prev = temp;
             
        }
       if(fast!=NULL){
           slow=slow->next;
       }
        while(prev){
            if(prev->val!=slow->val) return false;
            prev = prev->next;
            slow = slow->next;
        }
        return true;
    }
};