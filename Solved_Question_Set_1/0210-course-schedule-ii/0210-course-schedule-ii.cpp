class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> in(n,0);
        vector<vector<int>> adj(n,vector<int>());
        for(auto it:p)
            in[it[0]]++;
        for(auto it:p)
            adj[it[1]].push_back(it[0]);
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node])
            {
                in[it]--;
                if(in[it]==0)
                {
                    q.push(it);
                }
            }
        }
        if(ans.size()!=n) return {};
        return ans;
    }
};