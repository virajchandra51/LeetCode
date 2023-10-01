class Solution {
public:
    int MOD = 1e9+7;
    int countOrders(int n) {
        long long count = 1;
        for (int i = 2; i <= n; ++i) {
            count = (count * (2 * i - 1) * i) % MOD;
        }
        return (int)count;
    }
};