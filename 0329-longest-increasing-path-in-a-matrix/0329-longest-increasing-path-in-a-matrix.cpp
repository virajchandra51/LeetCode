class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<vector<int>>& matrix, int i, int j, int n, int m)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j] = 1;
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
        for(int k=0;k<4;k++)
        {
            int nx = i+dx[k];
            int ny = j+dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && matrix[i][j]<matrix[nx][ny])
                dp[i][j] = max(dp[i][j],1+helper(matrix,nx,ny,n,m));
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        dp.resize(n+1,vector<int>(m+1,-1));
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=max(ans,helper(matrix,i,j,n,m));
            }
        }
        return ans;
    }
};