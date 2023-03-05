class Solution {
public:
    int mod=1000000007;
    int solve(int n, int k, int target, vector<vector<int>>&dp){
        if(n==0)return target==0;
        if(dp[n][target]!=-1)return dp[n][target];
        int ans=0;
        for(int i=1;i<=k;i++){
            if(i<=target)ans=(ans+solve(n-1, k, target-i, dp))%mod;
        }return dp[n][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        return solve(n, k, target, dp);
    }
};