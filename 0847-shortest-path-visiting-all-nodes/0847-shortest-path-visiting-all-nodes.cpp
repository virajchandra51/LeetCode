class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n==0 || n==1)
            return 0;
        int checker = (1<<n)-1;
        queue<pair<int,int>> q;
        set<pair<int,int>> s;
        for(int i=0;i<n;i++)
        {
            int mask = (1<<i);
            q.push({i,mask});
            s.insert({i,mask});
        }
        int ans = 0;
        while(!q.empty())
        {
            int k = q.size();
            ans++;
            while(k--)
            {
                auto it = q.front();
                q.pop();
                for(auto i:graph[it.first])
                {
                    int newMask = it.second | (1<<i);
                    if(newMask==checker) return ans;
                    if(s.find({i,newMask})==s.end())
                    {
                        s.insert({i,newMask});
                        q.push({i,newMask});
                    }
                }
            }
        }
        return -1;
    }
};