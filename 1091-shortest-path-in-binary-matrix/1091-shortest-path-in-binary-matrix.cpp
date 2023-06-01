class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        int dx[] = {0,0,1,1,1,-1,-1,-1};
        int dy[] = {1,-1,0,1,-1,0,1,-1};
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int i = it.second.first;
            int j = it.second.second;
            int d = it.first;
            if(grid[i][j]==1) continue;
            grid[i][j]=1;
            if(i==n-1 && j==n-1) return d+1;
            for(int k=0;k<8;k++)
            {
                int ni = i+dx[k];
                int nj = j+dy[k];
                if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj]==0)
                {
                    q.push({d+1,{ni,nj}});
                }
            }
        }
        return -1;
    }
};