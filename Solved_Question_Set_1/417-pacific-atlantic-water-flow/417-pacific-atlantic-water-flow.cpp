class Solution {
public:
    void DFS(vector<vector<int>>& heights, vector<vector<int>> &vis, int i, int j)
    {
        int n = heights.size(),m = heights[0].size();
        vis[i][j]=1;
        if(i+1<n && !vis[i+1][j] && heights[i+1][j]>=heights[i][j])
            DFS(heights,vis,i+1,j);
        if(i-1>=0 && !vis[i-1][j] && heights[i-1][j]>=heights[i][j])
            DFS(heights,vis,i-1,j);
        if(j+1<m && !vis[i][j+1] && heights[i][j+1]>=heights[i][j])
            DFS(heights,vis,i,j+1);
        if(j-1>=0 && !vis[i][j-1] && heights[i][j-1]>=heights[i][j])
            DFS(heights,vis,i,j-1);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> P(n, vector<int>(m));
        vector<vector<int>> A(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            DFS(heights, P, i, 0);
            DFS(heights, A, i, m - 1);
        }
        for(int i = 0; i < m; i++) {
            DFS(heights, P, 0, i);
            DFS(heights, A, n - 1, i);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(P[i][j] && A[i][j]) {
                    ans.push_back(vector<int>{i, j});
                }
            }
        }
        return ans;
    }
};