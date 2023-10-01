class Solution {
public:
    vector<vector<int>> v;
    void subsets(vector<int> & nums,int n, int i, vector<int> a)
    {
        v.push_back(a);
        for(int id=i;id<nums.size();id++)
        {
            if(id!=i && nums[id]==nums[id-1]) continue;
            a.push_back(nums[id]);
            subsets(nums,n,id+1,a);
            a.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> a;
        subsets(nums,nums.size(),0,a);
        return v;
    }
};