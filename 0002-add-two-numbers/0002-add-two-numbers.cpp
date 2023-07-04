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
        ListNode* n=new ListNode(-1);
        ListNode* nh=n;
        ListNode* carry=new ListNode(0);
        while(l1&&l2)
        {
           int c=l1->val+l2->val+carry->val;
           int x=c%10;
           ListNode* s=new ListNode(x);
           c=c/10;
           n->next=s;
           carry->val= c;
           n=n->next;
           l1=l1->next;
           l2=l2->next;
        }
        while(l1)
        { 
            int c=l1->val+carry->val;
             ListNode* s=new ListNode(c%10);
              c=c/10;
               n->next=s;
            n=n->next;
                carry->val= c;
                 l1=l1->next;
                 
        }
       
        while(l2)
{
    int c=l2->val+carry->val;
             ListNode* s=new ListNode(c%10);
              c=c/10;
               n->next=s;
            n=n->next;
                carry->val= c;
                 l2=l2->next;
    }
    if(carry->val==1)
    n->next=carry;
    return nh->next;
    }
};