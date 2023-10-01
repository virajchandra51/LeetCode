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
    void re(ListNode* &head)
    {
        ListNode* prev = NULL; 
        ListNode* next = head;
        ListNode* curr = head;
        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return;
    }
    void reorderList(ListNode* head) {
        int c = 0;
        ListNode* first = head;
        while(first!=NULL)
        {
            c++;
            first=first->next;
        }
        first = head;
        ListNode* last = head;
        while(last->next!=NULL) last=last->next;
        c/=2;
        while(c--)
            first=first->next;
        re(first);
        first=head;
        // while(first)
        // {
        //     cout<<first->val;
        //     first=first->next;
        // }
        // while(last)
        // {
        //     cout<<last->val;
        //     last=last->next;
        // }
        first=head;
        ListNode* firstp = first;
        ListNode* lastp = last;
        int f=1;
        while(first!=last)
        {
            if(f)
            {
                first = first->next;
                firstp->next = last;
                firstp = first;
            }
            else
            {
                last = last->next;
                lastp->next = first;
                lastp = last;
            }
            f=!f;
        }
        
    }
};