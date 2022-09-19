class Solution {
public:
    set<vector<int>> v;
    void dfs(vector<int> &candidates, int i, int target, vector<int> &a, int n)
    {
        if(target<0 || i==n)
            return;
        if(target==0)
        {
            v.insert(a);
            return;
        }
        a.push_back(candidates[i]);
        dfs(candidates,i,target-candidates[i],a,n);
        dfs(candidates,i+1,target-candidates[i],a,n);
        a.pop_back();
        dfs(candidates,i+1,target,a,n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> a;
        dfs(candidates,0,target,a,candidates.size());
        vector<vector<int>> ans;
        for(auto it:v)
            ans.push_back(it);
        return ans;
    }
};