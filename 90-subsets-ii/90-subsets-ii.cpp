class Solution {
public:
    set<vector<int>> v;
    void subsets(vector<int> & nums,int n, int i, vector<int> a)
    {
        if(i==n)
        {
            sort(a.begin(),a.end());
            v.insert(a);
            return;
        }
        subsets(nums,n,i+1,a);
        a.push_back(nums[i]);
        subsets(nums,n,i+1,a);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> a;
        subsets(nums,nums.size(),0,a);
        vector<vector<int>> ans;
        for(auto it:v)
            ans.push_back(it);
        return ans;
    }
};