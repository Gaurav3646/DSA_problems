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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count =0;
        ListNode*  ptr = head;
        while(ptr){
            count++;
            ptr = ptr->next;
        }
        int rem = count%k;
        int size = count/k;
        vector<ListNode*> ansList(k, NULL);
        count =0;
        ptr = head;
        ansList[0] = head;
        // cout<<rem<<endl;
        int i = 1;
        while(ptr){
            int l = size;
            if(rem){
                l++;
            }
            count++;
            // cout<<l<<endl;
            ListNode* node;
            if(count==l){
                if(i<k){
                    ansList[i++] = ptr->next;
                    node = ptr->next;
                    ptr->next = NULL;
                    ptr = node;
                    
                }
                else{
                   ptr = ptr->next;   
                }
             if(rem)
                rem--;
                count =0;
            }
            else{
              ptr = ptr->next;  
            }
            
            
        }
        return ansList;
    }
};