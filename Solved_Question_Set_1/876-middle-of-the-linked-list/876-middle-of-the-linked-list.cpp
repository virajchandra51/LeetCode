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
    ListNode* middleNode(ListNode* head) {
        ListNode* h = head;
        int c=0;
        while(h!=NULL)
        {
            c++;
            h=h->next;
        }
        if(c&1)
        {
            c++;
            c/=2;
            while(head!=NULL)
            {
                c--;
                if(c==0)
                {
                    return head;
                }
                head=head->next;
            }
        }
        else
        {
            c/=2;
            c++;
            while(head!=NULL)
            {
                c--;
                if(c==0)
                {
                    return head;
                }
                head=head->next;
            }
        }
        return head;
    }
};