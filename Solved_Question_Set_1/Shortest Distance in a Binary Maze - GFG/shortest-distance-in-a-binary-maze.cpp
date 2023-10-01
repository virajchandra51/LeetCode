//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
         int n = grid.size(), m = grid[0].size();

        int sr = source.first, sc = source.second;

        int dr = destination.first, dc = destination.second;

            

        queue<vector<int>> q;

        q.push({sr, sc, 0});

        

        while(!q.empty())

        {

            auto top = q.front();

            q.pop();

            

            int i = top[0], j = top[1], dis = top[2];

            

            if(i == dr && j == dc)

                return dis;

                

            int dx[] = {-1, 1, 0, 0};

            int dy[] = {0, 0, -1, 1};

            

            for(int k=0; k<4; k++)

            {

                int r = i + dx[k];

                int c = j + dy[k];

                

                if(r >= 0 && r < n && c >= 0 && c<m && grid[r][c])

                {

                    q.push({r, c, dis+1});

                    grid[r][c] = 0;

                }

            }

        }

        

        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends