class Solution {
public:
    int M = 1000000007;
    // dp [i][j] = number of ways to make sum j using first i dices out of n
    // dp[n][targetSum] = ans
    // dp [i][j] += (dp[i][j]%M +dp[i-1][z]%M)%M;
    vector<vector<int>> dp;
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n+1,vector<int>(target+1));
        for(int i=1;i<=(min(k,target));i++)
            dp[1][i]=1;
        
        
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<target+1;j++)
            {
                for(int z=max(0,j-k);z<j;z++)
                    dp[i][j] = (dp[i][j]%M +dp[i-1][z]%M)%M;
            }
        }
        
        return dp[n][target];
    }
};