class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>res(n-2,vector<int>(n-2));
        int a,b,c;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                a=max({grid[i][j],grid[i][j+1],grid[i][j+2]});
                b=max({a,grid[i+1][j],grid[i+1][j+1],grid[i+1][j+2]});
                c=max({b,grid[i+2][j],grid[i+2][j+1],grid[i+2][j+2]});
                res[i][j]=c;
            }
        }
        return res;
    }
};