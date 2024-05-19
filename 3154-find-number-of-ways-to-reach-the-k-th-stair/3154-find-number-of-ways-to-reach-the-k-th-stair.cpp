class Solution {
public:
    map< pair<long long, pair<long long, long long>>, long long > dp;
    int solve(long long currentK, long long jump, long long f, int givenK)
    {
        if (currentK > 2e9)
            return 0;
        
        if (dp.count({currentK, {jump, f}}))
            return dp[{currentK, {jump, f}}];
        
        int ans = 0;
        
        if (f == 0 && currentK > 0)
            ans += solve(currentK - 1, jump, 1, givenK);
        ans += solve(currentK + (1LL << jump), jump + 1, 0, givenK) + (currentK == givenK);
        
        return dp[{currentK, {jump, f}}] = ans;
    }
    int waysToReachStair(int k) {
        return solve(1, 0, 0, k);
    }
};