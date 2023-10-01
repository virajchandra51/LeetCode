class Solution {
public:
    int ans = 0;
    int dfs(vector<vector<int>>& adj, int par, int node, vector<int> &vis, int k,vector<int> &values)
    {
        vis[node]=1;
        int sum = values[node];
        for(auto child:adj[node])
        {
            if(child==par) continue;
            sum+=dfs(adj,node,child,vis,k,values);
        }
        if(sum%k==0) ans++;
        return sum%k;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n,vector<int>());
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        dfs(adj,-1,0,vis,k,values);
        return ans;
    }
};