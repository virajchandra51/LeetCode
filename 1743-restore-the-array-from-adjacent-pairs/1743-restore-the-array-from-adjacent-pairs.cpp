class Solution {
public:
    void dfs(vector<int>& ans, int node, int par, unordered_map<int,vector<int>> &m)
    {
        ans.push_back(node);
        for(auto it:m[node])
        {
            if(it==par) continue;
            dfs(ans,it,node,m);
        }
        return;
    }
    vector<int> restoreArray(vector<vector<int>>& a) {
        unordered_map<int,vector<int>> m;
        unordered_map<int,int> m1;
        for(auto it : a)
        {
            m1[it[0]]++;
            m1[it[1]]++;
            m[it[0]].push_back(it[1]);
            m[it[1]].push_back(it[0]);
        }
        int node;
        for(auto it:m1)
        {
            if(it.second==1) node=it.first;
        }
        vector<int> ans;
        dfs(ans,node,-1,m);
        return ans;
    }
};