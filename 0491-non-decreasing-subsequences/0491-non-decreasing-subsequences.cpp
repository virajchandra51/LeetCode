class Solution {
public:
    set<vector<int>> ans;
    void dfs(vector<int>& nums, int pos, int n, vector<int> &a)
    {
        if(pos==n)
        {
            if(a.size()>=2)
            ans.insert(a);
            return;
        }
        dfs(nums,pos+1,n,a);
        if(a.size()==0)
        {
            a.push_back(nums[pos]);
            dfs(nums,pos+1,n,a);
            a.pop_back();
        }
        else
        {
            if(nums[pos]>=a[a.size()-1])
            {
                a.push_back(nums[pos]);
                dfs(nums,pos+1,n,a);
                a.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> a;
        dfs(nums,0,nums.size(),a);
        vector<vector<int>> res;
        for(auto it:ans)
            res.push_back(it);
        return res;
    }
};