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
    ListNode* deleteMiddle(ListNode* head) {
        int c=0;
        ListNode* n = head;
        while(n!=NULL)
        {
            c++;
            n=n->next;
        }
        if(c<=2)
        {
            if(c==2)
            head->next=NULL;
            else
                head=NULL;
            return head;
        }
        if(c&1)
        {
            c/=2;
            c++;
            n = head;
            while(n!=NULL)
            {
                c--;n=n->next;
                if(c==1)break;
                
            }
            n->val=n->next->val;
            n->next=n->next->next;
            return head;
        }
        c/=2;
        c++;
        n = head;
            while(n!=NULL)
            {
                n=n->next;
                c--;
                if(c==1)break;
            }
            n->val=n->next->val;
            n->next=n->next->next;
            return head;
        
    }
};