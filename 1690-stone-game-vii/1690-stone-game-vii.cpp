class Solution {
public:
    vector<vector<vector<int>>> dp;
    int helper(vector<int>& stones, int i, int j, int turn, int sum)
    {
        if(i>=j) return 0;
        if(dp[turn][i][j]!=-1) return dp[turn][i][j];
        int l = sum-stones[i];
        int r = sum-stones[j];
        if(turn)
        return dp[turn][i][j] = max(l+helper(stones,i+1,j,0,l),r+helper(stones,i,j-1,0,r));
        return dp[turn][i][j] = min(-l+helper(stones,i+1,j,1,l),-r+helper(stones,i,j-1,1,r));
    }
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        dp.resize(2,vector<vector<int>>(n,vector<int>(n,-1)));
        int sum = accumulate(stones.begin(),stones.end(),0);
        return abs(helper(stones,0,n-1,1,sum));
    }
};