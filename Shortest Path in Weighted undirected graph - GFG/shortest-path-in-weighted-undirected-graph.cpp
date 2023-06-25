//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<int> dis(n+1,1e9);
        vector<int> par(n+1,-1);
        queue<pair<int,int>> q;
        dis[1] = 0;
        for(int i=0;i<=n;i++) par[i]=i;
        vector<vector<pair<int,int>>> adj(n+1,vector<pair<int,int>>());
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});        
            adj[it[1]].push_back({it[0],it[2]});
        }
        q.push({1,0});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int node = it.first;
            int wt = it.second;
            for(auto i:adj[node])
            {
                int w = i.second;
                int nn = i.first;
                if(wt+w<dis[nn])
                {
                    dis[nn]=wt+w;
                    q.push({nn,wt+w});
                    par[nn]=node;
                }
            }
        }
        if(dis[n]==1e9) return {-1};
        int no = n;
        vector<int> ans;
        while(par[no]!=no)
        {
            ans.push_back(no);
            no = par[no];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends