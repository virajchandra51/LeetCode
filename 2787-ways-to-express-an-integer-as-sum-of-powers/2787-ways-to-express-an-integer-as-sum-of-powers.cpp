class Solution {
public:
    vector<int> a;
    vector<vector<int>> dp;
    int m = 1e9+7;
    int helper(int s, int i, int n)
    {
        if(n==0) return 1;
        if(n<0) return 0;
        if(i>=s)
        {
            if(n==0)
                return 1;
            else return 0;
        }
        if(dp[i][n]!=-1) return dp[i][n];
        int ways = 0;
        ways+=helper(s,i+1,n)%m;
        ways+=helper(s,i+1,n-a[i])%m;
        return dp[i][n]=ways%m;
    }
    int numberOfWays(int n, int x) {
        for(int i=1;;i++)
        {
            int b = pow(i,x);
            if(b<=n) a.push_back(b);
            else break;
        }
        int s = a.size();
        dp.resize(s+1,vector<int>(n+1,-1));
        return helper(s,0,n);
    }
};