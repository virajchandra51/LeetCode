class Solution {
public:
    int low, high, zero, one, mod=1e9+7;
    int solve(int len, vector<int>&dp){
        if(len>high)return 0;
        if(dp[len]!=-1)return dp[len];
        return dp[len]=((solve(len+zero, dp)+solve(len+one, dp)%mod)+(len>=low && len<=high))%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        this->low=low;this->high=high;this->one=one;this->zero=zero;
        vector<int>dp(100001, -1);
        return solve(0, dp);
    }
};