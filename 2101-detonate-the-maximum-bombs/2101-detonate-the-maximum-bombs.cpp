class Solution {
public:
    int dfs(vector<vector<int>>& adj, vector<int>& vis, int node)
    {
        vis[node]=1;
        int ans=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                // vis[it]=1;
                ans+=dfs(adj,vis,it);
            }
        }
        return ans;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n+1,vector<int>());
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==i) continue;
                long x = bombs[i][0]-bombs[j][0];
                x*=x;
                long y = bombs[i][1]-bombs[j][1];
                y*=y;
                long c = bombs[i][2];
                c*=c;
                if((x+y)<=c)
                {
                    adj[i].push_back(j);
                }
            }
        }
        int m = INT_MIN;
        for(int i=0;i<n;i++)
        {
            vector<int> vis(n+1,0);
            m = max(m,dfs(adj,vis,i));
        }
        return m;
    }
};