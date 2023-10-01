class Solution {
public:
    long long ans = 0;
    long long dfs(int node, int parent, vector<vector<int>> &adj, int seats)
    {
        long long nodes = 1;
        for(auto child:adj[node])
        {
            if(child==parent) continue;
            long long n = dfs(child,node,adj,seats);
            nodes+=n;
        }
        ans+=(ceil(1.0*nodes/seats));
        return nodes;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>> adj(roads.size()+1,vector<int>());
        for(auto it:roads)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(auto i:adj[0]) dfs(i,0,adj,seats);
        return ans;
    }
};