class Solution {
public:
    vector<vector<int>> ans;
    void c(vector<int> a, vector<int>& nums, int n, vector<int>& used)
    {
        if(a.size()==n)
        {
            ans.push_back(a);
            return;
        }
        for(int ind=0;ind<n;ind++)
        {
            if(used[ind]) continue;
            if(ind>0 && nums[ind]==nums[ind-1] && !used[ind-1]) continue;
            a.push_back(nums[ind]);
            used[ind]=1;
            c(a,nums,n,used);
            used[ind]=0;
            a.pop_back();
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> used(nums.size(),0);
        vector<int> a;
        c(a,nums,nums.size(),used);
        return ans;
    }
};