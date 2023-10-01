class Solution {
public:
    map<pair<int,int>,int> m;
    int dfs(int node, vector<vector<pair<int,int>>> &adj, int par)
    {
        int val = 0;
        if(m.find({node,par})!=m.end()) return m[{node,par}];
        for(auto child: adj[node])
        {
            if(child.first==par) continue;
            val+=child.second;
            val+=dfs(child.first,adj,node);
        }
        return m[{node,par}] = val;
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n, vector<pair<int,int>>());
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],0});
            adj[it[1]].push_back({it[0],1});
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
            ans[i] = dfs(i,adj,-1);
        }
        return ans;
    }
};