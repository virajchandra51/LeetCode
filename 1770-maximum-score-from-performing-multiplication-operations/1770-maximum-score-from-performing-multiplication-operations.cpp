class Solution {
public:
    int m,n;
    vector<vector<int>> memo;
    int maximumScore(vector<int>& nums, vector<int>& muls) {
        m = muls.size();
        n = nums.size();
        memo.resize(m+1,vector<int>(m+1,INT_MIN));
        return dp(0, n, 0, nums, muls);
    }
    int dp(int l, int n, int i, vector<int>& nums, vector<int>& muls) {
        if (i == m) return 0; // Picked enough m elements
        if (memo[l][i] != INT_MIN) return memo[l][i];
        int pickLeft = dp(l+1, n, i+1, nums, muls) + nums[l] * muls[i]; // Pick the left side
        int pickRight = dp(l, n, i+1, nums, muls) + nums[n-(i-l)-1] * muls[i]; // Pick the right side
        return memo[l][i] = max(pickLeft, pickRight);
    }
};