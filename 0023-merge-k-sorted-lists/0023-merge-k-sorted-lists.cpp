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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* itr=NULL;
        int min = INT_MAX;
        int index;
        ListNode* head=NULL;
        do{
            index = -1;
            min = INT_MAX;
        for(int i=0; i<lists.size(); i++){
            if(lists[i]!=NULL && min>lists[i]->val){
                min =lists[i]->val;
                index = i;
            }
        }
            if(index!=-1){
                if(head==NULL){
                    head = lists[index];
                    itr = lists[index];
                    
                }
                else {
                itr->next = lists[index];
                itr = itr->next;
            
                }
                    lists[index] = lists[index]->next;
                  itr->next =NULL;
                
            }
            cout<<index<<endl;
            
        }while(index!=-1);
        return head;
    }
};