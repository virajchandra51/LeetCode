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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*> a,b;
        ListNode* aa = headA;
        ListNode* bb = headB;
        while(headA!=NULL)
        {
            a.push_back(headA);
            headA=headA->next;
        }
        while(headB!=NULL)
        {
            b.push_back(headB);
            headB=headB->next;
        }
        headA=aa;
        headB=bb;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i=0;
        int j=0;
        while(i<a.size() && j<b.size() && a[i]==b[j])
        {
            i++;
            j++;
        }
        return i-1>=0 ? a[i-1] : NULL;
    }
};