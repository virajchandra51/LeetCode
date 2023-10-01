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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> a(m,vector<int>(n,-1));
        int tm=0;
        int bm=m-1;
        int lm=0;
        int rm=n-1;
        int k=1;
        while(true)
        {
            if(tm>bm) break;
            for(int i=lm;i<=rm;i++)
            {
                if(head!=NULL)
                {
                    a[tm][i]=head->val;
                    head=head->next;
                }
            }
            if(tm>=bm) break;
            tm++;
            for(int i=tm;i<=bm;i++)
            {
                if(head!=NULL)
                {
                    a[i][rm]=head->val;
                    head=head->next;
                }
            }
            rm--;
            if(lm>rm) break;
            for(int i=rm;i>=lm;i--)
            {
                if(head!=NULL)
                {
                    a[bm][i]=head->val;
                    head=head->next;
                }
            }
            bm--;
            for(int i=bm;i>=tm;i--)
            {
                if(head!=NULL)
                {
                    a[i][lm]=head->val;
                    head=head->next;
                }
            }
            if(lm>=rm) break;
            lm++;
        }
        return a;
    }
};