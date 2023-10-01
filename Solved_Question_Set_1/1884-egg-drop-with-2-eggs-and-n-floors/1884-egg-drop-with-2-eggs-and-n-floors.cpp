class Solution {
public:
    int twoEggDrop(int k) {
        int n = 2;
        vector<int>dp(n+1,0);
        int m;
        for (m = 0; dp[n] < k; m++) {
            for (int x = n; x > 0; x--) {
                dp[x] += 1 + dp[x - 1];
            }
        }
        return m;
    }
};