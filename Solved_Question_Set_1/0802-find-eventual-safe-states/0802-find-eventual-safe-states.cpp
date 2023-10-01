class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();
        vector<vector<int>> adj(n,vector<int>());
        vector<int> in(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:graph[i]) adj[it].push_back(i);
        }
        for(auto it:adj)
        {
            for(auto i:it) in[i]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            ans.push_back(it);
            for(auto i:adj[it])
            {
                in[i]--;
                if(in[i]==0) q.push(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};