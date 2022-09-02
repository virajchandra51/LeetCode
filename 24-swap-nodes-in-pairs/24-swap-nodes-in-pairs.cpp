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
    ListNode* swapPairs(ListNode* head) {
        ListNode* h = head;
        while(h!=NULL && h->next!=NULL)
        {
            int temp = h->val;
            h->val = h->next->val;
            h->next->val = temp;
            h=h->next->next;
        }
        return head;
    }
};