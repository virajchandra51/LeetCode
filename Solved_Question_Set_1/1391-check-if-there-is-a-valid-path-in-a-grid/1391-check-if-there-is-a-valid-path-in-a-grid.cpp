class Solution {
public:
    bool hasValidPath(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int i = it.first;
            int j = it.second;
            vis[i][j]=1;
            if(i==n-1 && j==m-1) return true;
            int d = g[i][j];
            if(d==1)
            {
                if(j-1>=0 && vis[i][j-1]==0)
                {
                    int di = g[i][j-1];
                    if(di==1 || di==4 || di==6)
                        q.push({i,j-1});
                }
                if(j+1<m && vis[i][j+1]==0)
                {
                    int di = g[i][j+1];
                    if(di==1 || di==3 || di==5)
                        q.push({i,j+1});
                }
            }
            else if(d==2)
            {
                if(i-1>=0 && vis[i-1][j]==0)
                {
                    int di = g[i-1][j];
                    if(di==2 || di==3 || di==4)
                        q.push({i-1,j});
                }
                if(i+1<n && vis[i+1][j]==0)
                {
                    int di = g[i+1][j];
                    if(di==2 || di==5 || di==6)
                        q.push({i+1,j});
                }   
            }
            else if(d==3)
            {
                if(j-1>=0 && vis[i][j-1]==0)
                {
                    int di = g[i][j-1];
                    if(di==1 || di==4 || di==6)
                        q.push({i,j-1});
                }
                if(i+1<n && vis[i+1][j]==0)
                {
                    int di = g[i+1][j];
                    if(di==2 || di==5 || di==6)
                        q.push({i+1,j});
                } 
            }
            else if(d==4)
            {
                if(j+1<m && vis[i][j+1]==0)
                {
                    int di = g[i][j+1];
                    if(di==1 || di==3 || di==5)
                        q.push({i,j+1});
                }
                if(i+1<n && vis[i+1][j]==0)
                {
                    int di = g[i+1][j];
                    if(di==2 || di==5 || di==6)
                        q.push({i+1,j});
                } 
            }
            else if(d==5)
            {
                if(i-1>=0 && vis[i-1][j]==0)
                {
                    int di = g[i-1][j];
                    if(di==2 || di==3 || di==4)
                        q.push({i-1,j});
                }
                if(j-1>=0 && vis[i][j-1]==0)
                {
                    int di = g[i][j-1];
                    if(di==1 || di==4 || di==6)
                        q.push({i,j-1});
                }
            }
            else if(d==6)
            {
                if(i-1>=0 && vis[i-1][j]==0)
                {
                    int di = g[i-1][j];
                    if(di==2 || di==3 || di==4)
                        q.push({i-1,j});
                }
                if(j+1<m && vis[i][j+1]==0)
                {
                    int di = g[i][j+1];
                    if(di==1 || di==3 || di==5)
                        q.push({i,j+1});
                }
            }
        }
        return false;
    }
};