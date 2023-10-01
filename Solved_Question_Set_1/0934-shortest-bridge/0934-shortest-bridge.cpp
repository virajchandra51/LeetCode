class Solution {
public:
    
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int i, int j, int n)
    {
        
    }
    void mark2(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j, int n)
    {
        if(i>=n || i<0 || j>=n || j<0 || vis[i][j]==1 || grid[i][j]==0)
            return;
        grid[i][j]=2;
        vis[i][j]=1;
        mark2(grid,vis,i+1,j,n);
        mark2(grid,vis,i-1,j,n);
        mark2(grid,vis,i,j+1,n);
        mark2(grid,vis,i,j-1,n);
        return;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        int f=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    mark2(grid,vis,i,j,n);
                    f=1;
                    break;
                }
            }
            if(f) break;
        }
        int ans = INT_MAX;
        int d[] = {0,1,0,-1,0};
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> vi(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2 && ((i-1>=0 && grid[i-1][j]==0) || (i+1<n && grid[i+1][j]==0) || (j-1>=0 && grid[i][j-1]==0) || (j+1<n && grid[i][j+1]==0)))
                {
                    q.push({0,{i,j}});
                }
            }
        }
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int st = it.first;
            int x = it.second.first;
            int y = it.second.second;
            vi[x][y]=1;
            for(int k=0;k<4;k++)
            {
                int nx = x+d[k];
                int ny = y+d[k+1];
                if(nx>=0 && nx<n && ny>=0 && ny<n)
                {
                    if(grid[nx][ny]==1)
                         return st;
                    else if(grid[nx][ny]==0 && vi[nx][ny]==0)
                    {
                        q.push({st+1,{nx,ny}});
                        vi[nx][ny]=1;
                    }
                }
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};