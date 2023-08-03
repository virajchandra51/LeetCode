class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int pos, int k) {
        auto l = upper_bound(begin(fruits), end(fruits), vector<int>{pos - k});
        int sum = 0, max_sum = 0;
        for (auto r = l; r != end(fruits) && (*r)[0] <= pos + k; ++r) {
            sum += (*r)[1];
            while(min(pos - 2 * (*l)[0] + (*r)[0], 2 * (*r)[0] - (*l)[0] - pos) > k)
                sum -= (*l++)[1];
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};