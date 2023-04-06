class Solution {
public:
    vector<vector<int>> ans;
    void c(vector<int> a, vector<int>& nums, int n)
    {
        if(a.size()==n)
        {
            ans.push_back(a);
            return;
        }
        for(int ind=0;ind<n;ind++)
        {
            auto it = find(a.begin(),a.end(),nums[ind]);
            if(it!=a.end()) continue;
            a.push_back(nums[ind]);
            c(a,nums,n);
            a.pop_back();
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> a;
        c(a,nums,nums.size());
        return ans;
    }
};