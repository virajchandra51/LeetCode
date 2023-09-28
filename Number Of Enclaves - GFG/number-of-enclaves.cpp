//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>&vis ,int row,int col,int row_ind, int col_ind)
    {
        vis[row_ind][col_ind]=0;
            int i=row_ind-1,j=col_ind;
            if(!(i<0||j<0||i>=row||j>col)&&vis[i][j]==1)
              dfs(vis,row,col,i,j);
              
              i=row_ind;j=col_ind+1;
            if(!(i<0||j<0||i>=row||j>col)&&vis[i][j]==1)
              dfs(vis,row,col,i,j);
              
              i=row_ind+1;j=col_ind;
            if(!(i<0||j<0||i>=row||j>col)&&vis[i][j]==1)
              dfs(vis,row,col,i,j);
              
              i=row_ind;j=col_ind-1;
            if(!(i<0||j<0||i>=row||j>col)&&vis[i][j]==1)
              dfs(vis,row,col,i,j);
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
       // vector<vector<int>>vis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
              {
                  if((grid[i][j]==1 )&&(i==0||j==0||i==n-1||j==m-1))
                  {
                      dfs(grid,n,m,i,j);
                  }
              }
            
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
               if(grid[i][j]==1) res++;
        }
        
        
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends