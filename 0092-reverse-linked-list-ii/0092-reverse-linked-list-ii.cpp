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
     ListNode* reverseList(ListNode* head,  ListNode* second ) {
        
         
        ListNode* first = head;
        ListNode* Node = NULL;
        while(first!=NULL){
            // cout<<first->val<<endl;
            Node =  first->next;
            first->next  = second;
            second = first;
            first = Node;
        }
        return second;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
         if(head->next==NULL || left==right) return head;
        ListNode* ptr  = head;
            ListNode* l = NULL;
            ListNode* r = NULL;
        ListNode* prev = NULL;
        int count = 1;
        while(ptr){
            
            if(count==left){
                l = ptr;
            }
            if(l==NULL){
                prev = ptr;
            }
             if(count==right){
                r = ptr;
                
            }
            ptr = ptr->next;
            count++;
        }
        ListNode* d = r;
        r = r->next;
        d->next = NULL;
       ListNode* revListPtr = reverseList(l, r);
        if(prev){
            
            prev->next = revListPtr;
            return head;
        }
        else{
 
            return revListPtr;
        }
        
    }
};