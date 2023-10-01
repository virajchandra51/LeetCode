//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
 
    // Function to detect cycle in a directed graph.
    bool dfs(int n, vector<int>& dfsvis, vector<int> &vis, vector<int> adj[])
    {
        vis[n]=1;
        dfsvis[n]=1;
        for(auto it:adj[n])
        {
            if(dfsvis[it]==1)
            return true;
            else if(vis[it]==0)
            {
                if(dfs(it,dfsvis,vis,adj))
                return true;
            }
        }
        dfsvis[n]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> dfsvis(V,0);
        for(int u=0;u<V;u++)
        {
            if(dfs(u,dfsvis,vis,adj))
            return true;
        }
        return false;
        
        
        // code here
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends