class Solution {
public:
    int solve(vector<int>& piles, int i, int j, int sum, vector<vector<int>>& dp) {
        if(i>j)
            return 0;
        if(i==j)
            return piles[i];
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = max(sum - solve(piles, i+1, j, sum-piles[i], dp), sum - solve(piles, i, j-1, sum-piles[j], dp));
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int sum = accumulate(piles.begin(), piles.end(), 0);
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int alexStones = solve(piles, 0, n-1, sum, dp);
        return alexStones > sum-alexStones;
    }

};