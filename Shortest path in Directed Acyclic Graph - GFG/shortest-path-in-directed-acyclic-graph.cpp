//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>adj[N];
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,int>>pq;
        vector<int>dist(N,1e9);
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty())
        {
            auto it=pq.front();
            pq.pop();
            int node=it.first;
            int dis=it.second;
            for(auto i:adj[node])
            {
                if(dis+i.second<dist[i.first])
                {
                    dist[i.first]=dis+i.second;
                    pq.push({i.first,dis+i.second});
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            if(dist[i]==1e9)dist[i]=-1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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