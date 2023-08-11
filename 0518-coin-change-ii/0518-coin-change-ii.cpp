class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& coins, int i, int N, int sum)
    {
        if(sum<0) return 0;
        if(sum==0) return 1;
        if(i>=N)
        {
            if(sum==0) return 1;
            return 0;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int nottake = helper(coins,i+1,N,sum);
        int take = 0;
        if(sum-coins[i]>=0)
        take+=helper(coins,i,N,sum-coins[i]);
        return dp[i][sum] = take+nottake;
    }
    int change(int sum, vector<int>& coins) {
        int N = coins.size();
        dp.resize(N+1,vector<int>(sum+1,-1));
        return helper(coins,0,N,sum);
    }
};