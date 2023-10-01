class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
        for(auto it:flights)
        adj[it[0]].push_back({it[1],it[2]});
        vector<int> dist(n,INT_MAX);
        queue<pair<int,int>> q;
        q.push({src,0});
        int stops=0;
        while(stops<=k && !q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto [node,distance] = q.front();
                q.pop();
                for(auto [neighbour,price]:adj[node])
                {
                    if(price+distance>=dist[neighbour]) continue;
                    dist[neighbour] = price+distance;
                    q.push({neighbour,dist[neighbour]});
                }
            }
            stops++;
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};