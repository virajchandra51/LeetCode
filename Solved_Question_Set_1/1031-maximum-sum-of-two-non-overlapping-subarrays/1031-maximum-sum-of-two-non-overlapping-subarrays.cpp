class Solution {
public:
//     0 6 5 2 2 5 1 9 4
//   0 0 6 11 13 15 20 21 30 34
    
    int maxSumTwoNoOverlap(vector<int>& a, int f, int s) {
        int n = a.size();
        vector<int> pre(n+1,0);
        for(int i=1;i<=n;i++)
            pre[i] = a[i-1]+pre[i-1];
        
        int p1=0,p2=f;
        int ans = -1;
        while(p2<=n)
        {
            int sum1 = pre[p2]-pre[p1];
            int sum2=-1;
            int l1=0,l2=s;
            while(l2<=p1)
            {
                sum2=max(sum2,pre[l2]-pre[l1]);
                l1++;
                l2++;
            }
            l1=p2;
            l2=p2+s;
            while(l2<=n)
            {
                sum2=max(sum2,pre[l2]-pre[l1]);
                l1++;
                l2++;
            }
            ans=max(ans,sum1+sum2);
            p1++;
            p2++;
        }
        return ans;
    }
};