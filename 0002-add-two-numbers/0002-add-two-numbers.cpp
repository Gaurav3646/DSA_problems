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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* Head= NULL;
        ListNode* ptr=NULL;
        int a=0, b=0, i=1;
        
        while(l1!=NULL&&l2!=NULL){
         
            a = l1->val+(a+b)/10;
            b = l2->val;
            
           ListNode* ptr1 = new ListNode();
            if(i==1){
                Head = ptr1;
                ptr = ptr1;
                ptr1->val = (a+b)%10;
                i=0;
            }
            else{
            ptr1->val = (a+b)%10;
            ptr->next = ptr1;
             ptr = ptr->next;
            }
           
            l1 = l1->next;
            l2 = l2->next;
            
            
        }
        b = (a+b);
        while(l2!=NULL){
             
            b = l2->val +b/10;
           ListNode* ptr1 = new ListNode();
            ptr1->val = b%10;
            ptr->next = ptr1;
            ptr = ptr->next;
            l2 = l2->next;
            
            
            
        }
          while(l1!=NULL){
             
            b = l1->val +b/10;
           ListNode* ptr1 = new ListNode();
            ptr1->val = b%10;
            ptr->next = ptr1;
            ptr = ptr->next;
            l1 = l1->next;
            
            
            
        }
        b = b/10;
        if(b==1){
       ListNode* ptr1 = new ListNode();
            ptr1->val = 1;
            ptr->next = ptr1;
            
        }
        return Head;
        
    }
};