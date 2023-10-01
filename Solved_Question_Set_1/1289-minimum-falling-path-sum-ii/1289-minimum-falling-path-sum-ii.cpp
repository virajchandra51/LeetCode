class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int m = INT_MAX;
                for(int k=0;k<n;k++)
                {
                    if(k==j) continue;
                    else m=min(m,grid[i-1][k]);
                }
                grid[i][j]+=m;
            }
        }
        for(auto i:grid)
        {
            for(auto j:i)cout<<j<<" ";
            cout<<endl;
        }
        int m = INT_MAX;
        for(auto it:grid[n-1]) m=min(m,it);
        return m;
    }
};