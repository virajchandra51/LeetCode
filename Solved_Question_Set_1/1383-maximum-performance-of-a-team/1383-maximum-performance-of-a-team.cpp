class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int MOD = 1e9 + 7;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) 
            v[i] = { efficiency[i], speed[i] };
        sort(v.rbegin(), v.rend());
        long speedSum = 0, ans = 0;
        priority_queue <int, vector<int>, greater<int>> pq;
        for (auto it:v) {
            pq.push(it.second);
            speedSum += it.second;
            if (pq.size() > k) {
                speedSum -= pq.top();
                pq.pop();
            }
            ans = max(ans, speedSum * it.first);
        }
        return ans % MOD;
    }
};