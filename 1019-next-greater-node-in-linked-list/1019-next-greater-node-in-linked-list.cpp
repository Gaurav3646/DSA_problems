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
    vector<int> nextLargerNodes(ListNode* head) {
         stack<int> temp;
        vector<int> ans;
        ListNode* ptr = head;
        while(ptr!=NULL){
            ans.push_back(ptr->val);
            ptr = ptr->next;
        }
        for(int i=0; i<ans.size(); i++){
            if(temp.empty()){
                temp.push(i);
            }
            else{
                while(!temp.empty() && ans[temp.top()]<ans[i]){
                    ans[temp.top()] = ans[i];
                    temp.pop();
                }
                temp.push(i);
                
                
            }
        }
         while(!temp.empty()){
                    ans[temp.top()] = 0;
                    temp.pop();
                }
        return ans;
    }
};