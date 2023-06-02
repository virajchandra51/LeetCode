class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int node)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(adj,vis,it);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& g) {
        int n = g.size();
        vector<vector<int>> adj(n+1,vector<int>());
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    if(g[i][j])
                    {
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
        }
        int c=0;
        vector<int> vis(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                c++;
                dfs(adj,vis,i);
            }
        }
        return c;
    }
};