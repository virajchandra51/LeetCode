class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>>&c)
    {   
        vis[node]=1;
        for(auto it:c[node])
        {
            if(vis[it]==0)
                dfs(it,vis,c);
        }
        return;
    }
    int makeConnected(int n, vector<vector<int>>& c) {
        if(c.size()<(n-1))
            return -1;
        int cc = 0;
        vector<vector<int>> v(n,vector<int>());
        for(auto it:c)
        {
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                dfs(i,vis,v);
                cc++;
            }
        }
        return cc-1;
    }
};