class Solution {
public:
    bool bfs(vector<vector<int>>& a, int n, int m)
    {
        vector<vector<int>> vis(n,vector<int>(m,0));
        int dx[]={0,0,1,-1};        
        int dy[]={1,-1,0,0};
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            if(a[0][i]==0) 
            {
                vis[0][i]=1;
                q.push({0,i});
            }
        }
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
            if(x==n-1) return true;
            for(int k=0;k<4;k++)
            {
                int nx = x+dx[k];
                int ny = y+dy[k];
                if(nx>=0 && nx<n && ny>=0 && ny<m && a[nx][ny]==0 && vis[nx][ny]==0)
                {
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> a(row,vector<int>(col,0));
        int l = 0;
        int h = cells.size()-1;
        int ans;
        while(l<=h)
        {
            int mid = (l+h)>>1;
            for(int i=0;i<mid;i++)
            {
                a[cells[i][0]-1][cells[i][1]-1]=1;
            }
            if(bfs(a,row,col))
            {
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
            for(int i=0;i<mid;i++)
            {
                a[cells[i][0]-1][cells[i][1]-1]=0;
            }
        }
        return ans;
    }
};