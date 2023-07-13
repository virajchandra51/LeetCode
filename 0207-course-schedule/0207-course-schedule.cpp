class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int> &vis, vector<int> &st,int node)
    {
        vis[node]=1;
        st[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(adj,vis,st,it)) return true;
            }
            else if(st[it]) return true;
        }
        st[node]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& ad) {
        vector<vector<int>> adj(n+1,vector<int>());
        for(auto it:ad)
            adj[it[0]].push_back(it[1]);
        vector<int> vis(n+1,0);
        vector<int> st(n+1,0);
        for(int i = 0; i < n; i++)
        if (!vis[i] && dfs(adj, vis, st, i))
            return false;
        return true;
    }
};