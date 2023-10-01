class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        const int INF = 1e9;
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for (int i = 0; i <= n; i++) {
            int tapStart = max(0, i - ranges[i]);
            int tapEnd = min(n, i + ranges[i]);
            for (int j = tapStart; j <= tapEnd; j++) {
                dp[tapEnd] = min(dp[tapEnd], dp[j] + 1);
            }
        }
        if (dp[n] == INF) {
            return -1;
        }
        return dp[n];
    }
};