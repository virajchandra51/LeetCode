class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=1;i<=(n/2);i++)
        {
            dp[2*i] = dp[i];
            if(i==n/2 && n%2==0)
            break;
            dp[2*i+1] = dp[i]+dp[i+1];
        }
        int ans=-1;
        for(auto it:dp)
            ans=max(ans,it);
        return ans;
    }
};