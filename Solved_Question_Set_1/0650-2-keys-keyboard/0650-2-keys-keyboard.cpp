class Solution {
public:
    // n=1 0
    // n=2 2
    // n=3 3
    // n=4 4
    // n=5 5
    // n=6 5
    // n=7 7
    // n=8 6
    // n=9 6
    // n=10 7
    // n=11 11
    // n=12 7
    // n=13 13
    // n=14 9
    // n=15 
    int minSteps(int n) {
        if(n==1) return 0;
        if(n==2) return 2;
        vector<int> dp(n+1,0);
        dp[2] = 2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=INT_MAX;
            for(int j=1;j<i;j++)
            {
                if(i%j==0)
                {
                    dp[i] = min(dp[i],dp[j]+i/j);
                }
            }
        }
        return dp[n];
    }
};