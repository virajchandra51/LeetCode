class Solution {
public:
    vector<vector<int>> dp;
    vector<int> pre;
    int helper(vector<int>& a, int n, int i, int j)
    {
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        for(int k=i;k<j;k++)
        {
            int pre1 = pre[k]-(i>0?pre[i-1]:0);
            int pre2 = pre[j]-pre[k];
            if(pre1==pre2) ans = max({ans,pre1+helper(a,n,i,k),pre2+helper(a,n,k+1,j)});
            else if(pre1>pre2) ans=max(ans,pre2+helper(a,n,k+1,j));
            else ans = max(ans,pre1+helper(a,n,i,k));
        }
        return dp[i][j] = ans;
    }
    int stoneGameV(vector<int>& a) {
        int n = a.size();
        pre.resize(n,0);
        dp.resize(n,vector<int>(n,-1));
        pre[0] = a[0];
        for(int i=1;i<n;i++) pre[i] = pre[i-1]+a[i];
        return helper(a,n,0,n-1);
    }
};