class Solution {
public:
    int solve(int curr, int n, vector<int>&dp){
        if(n==0)
            return 0;
        if(curr*curr>n)
            return 1e5;
        if(dp[n]!=-1)
            return dp[n];
        int take=1e5; 
        int notake=solve(curr+1, n, dp);
        if(curr*curr<=n)
            take=1+solve(curr, n-(curr*curr), dp);
        return dp[n]=min(take, notake);
    }
    int numSquares(int n) {
        vector<int>dp(n+1, -1);
        return solve(1, n, dp);
    }
};