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
        ListNode* x1 = new ListNode(-1);
        ListNode* x1h = x1;
        ListNode* x2 = new ListNode(-1);
        ListNode* x2h = x2;
        ListNode* curr = head;
        while(curr!=NULL)
        {
            if(curr->val<x)
            { 
                x1->next = new ListNode(curr->val);
                x1=x1->next;
            }
            else
            {
                x2->next = new ListNode(curr->val);
                x2=x2->next;
            }
            curr=curr->next;
        }
        if(x2h->next!=NULL)
        x1->next=x2h->next;
        return x1h->next;
    }
};