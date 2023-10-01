class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        long res = INT_MIN;
        for(int i=0;i<k;i++)
        {
            long l = 0;
            long r = 1e9;
            long ans=-1;
            while(l<=r)
            {
                long mid = (l+r)>>1;
                long c = 0;
                for(int j=0;j<n;j++)
                {
                    long re = mid*composition[i][j];
                    re-=stock[j];
                    if(re>0) c+=(re*cost[j]);
                }
                if(c<=budget)
                {
                    ans=mid;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
            res=max(res,ans);
        }
        return (int)res;
    }
};