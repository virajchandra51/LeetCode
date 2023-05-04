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
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        int x,y,carry=0;
        while(l1 || l2 || carry)
        {
            x=l1 ? l1->val:0;
            y=l2 ? l2->val:0;
            int sum = carry+x+y;
            curr->next = new ListNode(0);
            curr->val = sum%10;
            carry = sum/10;
            curr = curr->next;
            l1=l1?l1->next:NULL;
            l2=l2?l2->next:NULL;   
        }
        curr=dummy;
        while(curr->next->next!=NULL)
            curr=curr->next;
        if(carry)
            curr->next->val=1;
        else
            curr->next=NULL;
        return dummy;
    }
};