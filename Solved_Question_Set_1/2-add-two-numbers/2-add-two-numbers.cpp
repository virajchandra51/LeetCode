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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* n = new ListNode();
        ListNode* nn = n;
        while(l1!=NULL && l2!=NULL)
        {
            int sum = l1->val+l2->val+carry;
            if(sum>9)
            {
                sum%=10;
                carry=1;
            }
            else
                carry=0;
            n->next = new ListNode(sum);
            n = n->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL)
        {
            int sum = l1->val+carry;
            if(sum>9)
            {
                sum%=10;
                carry=1;
            }
            else
                carry=0;
            n->next = new ListNode(sum);
            n = n->next;
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            int sum = l2->val+carry;
            if(sum>9)
            {
                sum%=10;
                carry=1;
            }
            else
                carry=0;
            n->next = new ListNode(sum);
            n = n->next;
            l2=l2->next;
        }
        if(carry==1)
            n->next = new ListNode(1);
        return nn->next;
    }
};