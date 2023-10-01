class Solution {
public:
     int dp[12 + 1][10000 + 1];
    
    int findLowestCoins(vector<int> &coins, int cur, int amount) {
        if (cur == coins.size() || amount <= 0)
            return (amount == 0) ? 0 : INT_MAX - 1;   
        
        if (dp[cur][amount] != -1)
            return dp[cur][amount];
        
        int res = -1;
        if (coins[cur] > amount) {
            int doNotTakeCoin = 0 + findLowestCoins(coins, cur + 1, amount - 0);
            dp[cur][amount] = res = doNotTakeCoin;
        }
        else {
            int takeCoin = 1 + findLowestCoins(coins, cur + 0, amount - coins[cur]);
            int doNotTakeCoin = 0 + findLowestCoins(coins, cur + 1, amount - 0);
            dp[cur][amount] = res = min(takeCoin, doNotTakeCoin);
        }
        return dp[cur][amount] = res;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int res = findLowestCoins(coins, 0, amount);
        return (res == INT_MAX - 1 ) ? -1 : res;
    }
};