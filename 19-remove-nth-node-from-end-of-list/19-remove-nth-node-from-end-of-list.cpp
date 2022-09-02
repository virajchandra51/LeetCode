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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* h = head;
        int c=0;
        while(h!=NULL)
        {
            c++;
            h=h->next;
        }
        c-=n;
        if(c==0)
        {
            return head->next;
        }
        h = head;
        while(h!=NULL)
        {
            c--;
            if(c==0)
            {
                h->next = h->next->next;
                break;
            }
            h=h->next;
        }
        return head;
    }
};