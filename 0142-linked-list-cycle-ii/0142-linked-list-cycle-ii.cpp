/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* s;
    ListNode *connectCycle(ListNode* head)
    {
        while(head!=s)
        {
            head=head->next;
            s=s->next;
        }
        return head;
    }
    int checkCycle(ListNode* head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(slow && slow->next && fast && fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                s=slow;
                return 1;
            }
        }
        return -1;
    }
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return NULL;
        int check = checkCycle(head);
        if(check==-1)
            return NULL;
        return connectCycle(head);
    }
};