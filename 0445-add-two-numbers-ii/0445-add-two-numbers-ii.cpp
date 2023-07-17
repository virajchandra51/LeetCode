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
    ListNode* rev(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* next;
        ListNode* curr = head;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = rev(l1);
        l2 = rev(l2);
        int carry = 0;
        ListNode* n = new ListNode(-1);
        ListNode* dum = n;
        while(l1 && l2)
        {
            int s = l1->val+l2->val+carry;
            carry = s/10;
            s%=10;
            n->next = new ListNode(s);
            n = n->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            int s = l1->val+carry;
            carry = s/10;
            s%=10;
            n->next = new ListNode(s);
            n = n->next;
            l1 = l1->next;
        }
        while(l2)
        {
            int s = l2->val+carry;
            carry = s/10;
            s%=10;
            n->next = new ListNode(s);
            n = n->next;
            l2 = l2->next;
        }
        if(carry>0)
        {
            n->next = new ListNode(carry);
            n = n->next;
        }
        return dum->next = rev(dum->next);
    }
};