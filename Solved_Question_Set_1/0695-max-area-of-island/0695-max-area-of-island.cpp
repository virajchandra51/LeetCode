class Solution {
public:
    int dfs(int i, int j, int n, int m, vector<vector<int>>& grid)
    {
        grid[i][j]=0;
        int ans=1;
        if(i+1<n && grid[i+1][j]==1)
            ans+=dfs(i+1,j,n,m,grid);
        if(i-1>=0 && grid[i-1][j]==1)
            ans+=dfs(i-1,j,n,m,grid);
        if(j-1>=0 && grid[i][j-1]==1)
            ans+=dfs(i,j-1,n,m,grid);
        if(j+1<m && grid[i][j+1]==1)
            ans+=dfs(i,j+1,n,m,grid);
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    ans=max(ans,dfs(i,j,n,m,grid));
                }
            }
        }
        return ans;
    }
};