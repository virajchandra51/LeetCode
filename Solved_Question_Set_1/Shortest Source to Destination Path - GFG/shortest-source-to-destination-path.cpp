//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        vector<vector<int>> vis(N,vector<int>(M,0));
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        vis[0][0]=1;
        if(A[X][Y]==0) return -1;
        if(A[0][0]==0) return -1;
        int dis[] = {0,1,0,-1,0};
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int x = it.second.first;
            int y = it.second.second;
            int d = it.first;
            if(x==X && y==Y) return d;
            for(int k=0;k<4;k++)
            {
                int nx = x+dis[k];
                int ny = y+dis[k+1];
                if(nx>=0 && nx<N && ny>=0 && ny<M && vis[nx][ny]==0 && A[nx][ny]==1)
                {
                    vis[nx][ny]=1;
                    q.push({d+1,{nx,ny}});
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
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends