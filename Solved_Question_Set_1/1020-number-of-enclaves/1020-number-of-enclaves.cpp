class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int c=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])c++;
            }
        }
        vector<vector<int>> vis(n,vector<int>(m,0));
        int x[] = {-1,1,0,0};
        int y[] = {0,0,-1,1};
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]) 
            {
                vis[i][0]=1;
                c--;
                q.push({i,0});
            }
            if((m-1)!=0)
            {
                if(grid[i][m-1]) 
                {
                    vis[i][m-1]=1;
                    c--;
                    q.push({i,m-1});
                }
            }
        }
        for(int i=1;i<m-1;i++)
        {
            if(grid[0][i]) 
            {
                vis[0][i]=1;
                c--;
                q.push({0,i});
            }
            if((n-1)!=0)
            {
                if(grid[n-1][i])
                {
                    vis[n-1][i]=1;
                    c--;
                    q.push({n-1,i});
                }
            }
        }
        while(!q.empty())
        {
            auto cor = q.front();
            q.pop();
            int xcor = cor.first;
            int ycor = cor.second;
            for(int i=0;i<4;i++)
            {
                int nxcor = xcor+x[i];
                int nycor = ycor+y[i];
                if(nxcor>=0 && nxcor<n && nycor>=0 && nycor<m && vis[nxcor][nycor]==0 && grid[nxcor][nycor]==1)
                {
                    vis[nxcor][nycor]=1;
                    q.push({nxcor,nycor});
                }
            }
        }
        
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                if(vis[i][j]) c--;
            }
        }
        return c;
    }
};