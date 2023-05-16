class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int a = 0;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i>0 && j>0 && mat[i-1][j-1]==1)
                {
                    dp[i][j] = 1+min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]});
                    a+=dp[i][j];
                }
            }
        }
        return a;
    }
};