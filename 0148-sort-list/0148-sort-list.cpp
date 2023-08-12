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
  static bool cmp(const ListNode* n1, const ListNode* n2) {
        return n1->val < n2->val;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL) return NULL;
        vector<ListNode*> arr;
        ListNode* ptr = head;
        while (ptr != NULL) {
            arr.push_back(ptr);
            ptr = ptr->next;
        }
        sort(arr.begin(), arr.end(), cmp);
        head = arr[0];
        ptr = head;
        for (int i = 1; i < arr.size(); i++) {
            ptr->next = arr[i];
            ptr = ptr->next;
        }
        ptr->next = NULL;
        return head;
    }
};
