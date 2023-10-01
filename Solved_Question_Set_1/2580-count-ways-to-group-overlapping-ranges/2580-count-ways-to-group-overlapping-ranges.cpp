class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int powerOf2(int n) {
        if(n == 1) return 2;
        long long ans = powerOf2(n / 2);
        ans = (ans * ans) % MOD;
        if(n % 2 == 1) ans = (ans * 2) % MOD;
        return ans;
    }
    int countWays(vector<vector<int>>& ranges) {
        sort(begin(ranges), end(ranges));
        int count = 1, lastMax = ranges[0][1];
        // merge intervals
        for(int i = 1; i < size(ranges); ++i) {
            int currMin = ranges[i][0];
            if(currMin > lastMax) ++count;
            lastMax = max(lastMax, ranges[i][1]);
        }
        return powerOf2(count);
        
    }
};