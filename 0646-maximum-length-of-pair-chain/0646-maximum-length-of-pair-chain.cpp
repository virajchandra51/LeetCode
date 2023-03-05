class Solution {
public:
    int solve(int index, vector<vector<int>>& pairs, int prev, vector<vector<int>>&dp){
        if(index>=pairs.size())return 0;
        if(dp[index][prev+1]!=-1)return dp[index][prev+1];
        int take=0, notake=solve(index+1, pairs, prev, dp);
        if(prev==-1 || pairs[prev][1]<pairs[index][0])
            take=1+solve(index+1, pairs, index, dp);
        return dp[index][prev+1]=max(take, notake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n=pairs.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return solve(0, pairs, -1, dp);
    }
};