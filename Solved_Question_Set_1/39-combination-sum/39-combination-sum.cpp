class Solution {
public:
    vector<vector<int>> v;
    void dfs(vector<int> &candidates, int i, int target, vector<int> &a, int n)
    {
        if(target<0 || i==n)
            return;
        if(target==0)
        {
            v.push_back(a);
            return;
        }
        dfs(candidates,i+1,target,a,n);
        a.push_back(candidates[i]);
        dfs(candidates,i,target-candidates[i],a,n);
        a.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> a;
        dfs(candidates,0,target,a,candidates.size());
        return v;
    }
};