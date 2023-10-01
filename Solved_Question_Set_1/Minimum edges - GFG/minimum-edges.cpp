//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            vector<vector<pair<int,int>>> adj(n+1,vector<pair<int,int>>());
            for(auto it:edges)
            {
                adj[it[0]].push_back({0,it[1]});
                adj[it[1]].push_back({1,it[0]});
            }
            queue<pair<int,int>> q;
            vector<int> dis(n+1,1e9);
            dis[src]=0;
            q.push({0,src});
            while(!q.empty())
            {
                auto it = q.front();
                q.pop();
                int node = it.second;
                int wt = it.first;
                for(auto i:adj[node])
                {
                    int no = i.second;
                    int wtt = i.first;
                    if(dis[no]>(wt+wtt))
                    {
                        dis[no] = wt+wtt;
                        q.push({wt+wtt,no});
                    }
                }
            }
            return dis[dst]==1e9?-1:dis[dst];
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> edges(m,vector<int> (2));
        for(auto &j:edges)
            for(auto &i:j)
                cin>>i;
        int src,dst;
        cin>>src>>dst;
        Solution s;
        cout<<s.minimumEdgeReversal(edges,n,src,dst)<<endl;
    }
    return 0;
}
// } Driver Code Ends