class Solution {
public:
    void dfs(vector<vector<int>>& land, int i, int j, int n, int m)
    {
        land[i][j]=0;
        int d[]={0,1,0,-1,0};
        for(int k=0;k<4;k++)
        {
            int nx = i+d[k];
            int ny = j+d[k+1];
            if(nx>=0 && nx<n && ny>=0 && ny<m && land[nx][ny]==1)
                dfs(land,nx,ny,n,m);
        }
        return;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int n = land.size();
        int m = land[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(land[i][j]==1)
                {
                    vector<int> d;
                    d.push_back(i);
                    d.push_back(j);
                    int ci = i;
                    int cj = j;
                    while(ci+1<n && land[ci+1][j]==1) ci++;
                    while(cj+1<m && land[ci][cj+1]==1) cj++;
                    d.push_back(ci);
                    d.push_back(cj);
                    dfs(land,i,j,n,m);
                    ans.push_back(d);
                }
            }
        }
        return ans;
    }
};