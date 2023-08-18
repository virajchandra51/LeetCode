class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> in(n,0);
        vector<vector<int>> adj(n,vector<int>(n,0));
        int m=INT_MIN;
        for(auto it:roads)
        {
            in[it[0]]++;
            in[it[1]]++;
            adj[it[0]][it[1]]=1;
            adj[it[1]][it[0]]=1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                m=max(m,in[i]+in[j]-adj[i][j]);
            }
        }
        return m;
    }
};