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
    private:
    ListNode*reverse(ListNode* &head){
        ListNode*curr=head;
        ListNode*next=NULL;
        ListNode*prev=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
        return prev;
    }
    
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*temp=head;
        int count=1;
        reverse(temp);
        head = temp;
        if(temp==NULL) {
            return NULL;
        }
       else if(n==1){
            temp = temp->next;
           head = temp;
        }
        else{
            while(count<n-1){
                temp=temp->next;
                count++;
            }
        
            ListNode*flag =temp->next;
            temp->next =flag->next;
            delete(flag);
        }
       
       reverse(head);
        return head;
    }
   
};