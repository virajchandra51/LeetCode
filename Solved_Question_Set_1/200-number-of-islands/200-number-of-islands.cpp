class Solution {
public:
    void mark_island_DFS(vector<vector<char>>& grid, int x ,int y ,int row, int col)
    {
        if(x<0 || y<0 ||x>=row || y>=col || grid[x][y]!='1')
            return;
        grid[x][y]='2';
        mark_island_DFS(grid,x-1,y,row,col);
        mark_island_DFS(grid,x+1,y,row,col);
        mark_island_DFS(grid,x,y-1,row,col);
        mark_island_DFS(grid,x,y+1,row,col);
    }
    int numIslands(vector<vector<char>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int row = grid.size();
        int col = grid[0].size();
        int no_of_islands = 0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1')
                {
                    mark_island_DFS(grid,i,j,row,col);
                    no_of_islands++;
                }
            }
        }
        return no_of_islands;
    }
};