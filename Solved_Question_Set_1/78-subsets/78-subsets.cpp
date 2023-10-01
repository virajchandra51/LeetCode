class Solution {
public:
    vector<vector<int>> v;
    void subsets(vector<int> & nums,int n, int i, vector<int> a)
    {
        if(i==n)
        {
            v.push_back(a);
            return;
        }
        subsets(nums,n,i+1,a);
        a.push_back(nums[i]);
        subsets(nums,n,i+1,a);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> a;
        subsets(nums,nums.size(),0,a);
        return v;
    }
};