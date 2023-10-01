class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rot = 0;
        int fre = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    rot++;
                    q.push({i,j});
                }
                if(grid[i][j]==1)
                    fre++;
            }
        }
        if(fre==0) return 0;
        int d[]={0,1,0,-1,0};
        int t=0;
        while(!q.empty())
        {
            int k = q.size();
            while(k--)
            {
                auto it = q.front();
                q.pop();
                int x = it.first;
                int y = it.second;
                for(int l=0;l<4;l++)
                {
                    int nx = x+d[l];
                    int ny = y+d[l+1];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1)
                    {
                        fre--;
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                    }
                }
            }
            t++;
            if(fre==0) return t;
        }
        return -1;
    }
};