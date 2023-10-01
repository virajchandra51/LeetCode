class Solution {
public:
    void dfs(int &ans, vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int n, int m)
    {
        int d[] = {0,1,0,-1,0};
        if(grid1[i][j]==0 && grid2[i][j]==1)
        {
            ans=0;
            return;
        }
        grid2[i][j]=0;
        for(int k=0;k<4;k++)
        {
            int nx = i+d[k];
            int ny = j+d[k+1];
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid2[nx][ny]==1)
            {
                dfs(ans,grid1,grid2,nx,ny,n,m);
            }
        }
        return;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int c = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j]==1)
                {
                    int ans = 1;
                    dfs(ans,grid1,grid2,i,j,n,m);
                    if(ans) c++;
                }
            }
        }
        return c;
    }
};