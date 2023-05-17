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
    int pairSum(ListNode* head) {
//       ListNode* slow=head;
//       ListNode* fast=head;
//       ListNode* prev = NULL;
//       while(fast){
//         fast = fast->next->next;
//            ListNode* node = slow;
//            slow = slow->next;
//           node->next = prev;
//           prev = node;
         
          
//           }
//         int mx = INT_MIN;
//         while(slow){
//             mx = max(slow->val+prev->val, mx);
//             slow = slow->next;
//             prev = prev->next;
//         }
//         return mx;
        ListNode* ptr=head;
        vector<int> vect;
        while(ptr){
            vect.push_back(ptr->val);
            ptr = ptr->next;
        }
        int mx = INT_MIN;
        int s = 0;
        int e = vect.size()-1;
        while(s<e){
           mx = max(mx, vect[s]+vect[e]);
            s++;
            e--;
        }
        return mx;
    }
};