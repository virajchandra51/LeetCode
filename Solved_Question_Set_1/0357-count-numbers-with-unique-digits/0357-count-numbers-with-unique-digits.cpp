class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)
            return 1;
        if(n==1)
            return 10;
        vector<int> dp(n+1,0);
        dp[1]=10;
        for(int i=2;i<=n;i++)
        {
            int f = 81;
            int c = i;
            int g = 8;
            while(c>2)
            {
                f*=g;
                g--;
                c--;
            }
            dp[i]=dp[i-1]+f;
        }
        return dp[n];
    }
};