class Solution {
public:
    int dp[3100][1001];
    int s, e, mod=1e9+7;
    long long solve(int curr, int k){
        if(curr==e)if(k==0)return 1;
        if(k==0)return 0;
        if(dp[curr+1000][k]!=-1)return dp[curr+1000][k];
        long long ans=solve(curr+1, k-1);
        if((e-curr+1)<=(k-1))ans+=solve(curr-1, k-1);
        return dp[curr+1000][k]=ans%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        e=endPos;
        s=startPos;
        if(abs(startPos-endPos)>k)return 0;
        memset(dp, -1, sizeof(dp));
        return solve(startPos, k);
    }
};