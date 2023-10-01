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
    ListNode* reverse(ListNode* begin, ListNode* end)
    {
        ListNode* prev = begin;
        ListNode* curr = begin->next;
        ListNode* next = begin->next;
        ListNode* first = begin->next;
        while(curr!=end)
        {
            next=curr->next;
            curr->next= prev;
            prev=curr;
            curr=next;
        }
        begin->next = prev;
        first->next = curr;
        return first;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==1) return head;
        ListNode* begin = new ListNode(-1);
        begin->next = head;
        ListNode* ans = begin;
        int i=0;
        while(head!=NULL)
        {
            i++;
            if(i%k==0)
            {
                begin = reverse(begin,head->next);
                head = begin->next;
            }
            else
            {
                head=head->next;
            }
        }
        return ans->next;
    }
};