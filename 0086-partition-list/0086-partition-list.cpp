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
    ListNode* partition(ListNode* head, int x) {
     if(head==NULL)   return NULL;
        ListNode* head1 = NULL;
        ListNode* head2 = NULL;
        ListNode* ptr1 = NULL;
        ListNode* ptr2 = NULL;
        
        ListNode* ptr = head;
       
            if(head->val>=x){
                head2 = head;
                 ptr2 = head2;
            }
        else if(head->val<x){
            head1 = head;
             ptr1 = head1;
        }
        
        while(ptr->next){
            if(ptr->next->val>=x){
                if(!ptr2){
                    head2  = ptr->next;
                    ptr2 = head2;
                }
                else{
                ptr2->next = ptr->next;
                    ptr2 = ptr2->next;
                }
                
            }
            else if(ptr->next->val<x){
             
                if(!ptr1){
                    head1  = ptr->next;
                    ptr1 = head1;
                }
                else{
                ptr1->next = ptr->next;
                    ptr1 = ptr1->next;
                }
                 
            }
           
            ptr = ptr->next;
        }
        if(!ptr1) return head2;
        if(!ptr2) return head1;
        ptr1->next =  head2;
        ptr2->next = NULL;
        return head1;
        
    }
};