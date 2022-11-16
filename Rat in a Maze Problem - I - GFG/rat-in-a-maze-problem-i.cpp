//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    void bfs(vector<vector<int>> &m, int n, string s, int i ,int j,vector<vector<int>> vis)
    {   
        if(i<0 || j<0 || i>=n || j>=n || m[i][j]==0 || vis[i][j]==1)
        return;
        if(i==n-1 && j==n-1)
        {
            ans.push_back(s);return;
        }
        vis[i][j]=1;
        bfs(m,n,s+'R',i,j+1,vis);
        bfs(m,n,s+'L',i,j-1,vis);
        bfs(m,n,s+'U',i-1,j,vis);
        bfs(m,n,s+'D',i+1,j,vis);
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0]==0 || m[n-1][n-1]==0)
        return {};
        vector<vector<int>> vis(n,vector<int>(n,0));
        bfs(m,n,"",0,0,vis);
        return ans;
        // Your code goes here
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends