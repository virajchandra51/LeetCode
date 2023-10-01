class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]>0)
                    ans++;
            }
        }
        for(int i=0;i<grid.size();i++)
        {
            auto it = max_element(grid[i].begin(),grid[i].end());
            ans+=(*it);
        }
        vector<vector<int>> v(grid[0].size(),vector<int> (grid.size()));
        for(int i=0;i<grid[0].size();i++)
        {
            for(int j=0;j<grid.size();j++)
                v[i][j] = grid[j][i];
        }
        for(int i=0;i<grid.size();i++)
        {
            auto it = max_element(v[i].begin(),v[i].end());
            ans+=(*it);
        }
        return ans;
    }
};