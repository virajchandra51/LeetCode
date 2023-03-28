class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m));
        vector<vector<int>> dis(n,vector<int>(m));
        int rowS[] = {-1,0,0,1};
        int colS[] = {0,-1,1,0};
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int nrow = it.first.first;
            int ncol = it.first.second;
            int steps = it.second;
            dis[nrow][ncol] = steps;
            for(int i=0;i<4;i++)
            {
                int nnrow = nrow + rowS[i];
                int nncol = ncol + colS[i];
                if(nnrow>=0 && nnrow<n && nncol>=0 && nncol<m && vis[nnrow][nncol]==0)
                {
                    q.push({{nnrow,nncol},steps+1});
                    vis[nnrow][nncol]=1;
                }
            }
        }
        return dis;
    }
};