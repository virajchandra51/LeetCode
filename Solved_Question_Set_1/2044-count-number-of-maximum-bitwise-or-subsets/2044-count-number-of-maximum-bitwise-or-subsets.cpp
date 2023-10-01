class Solution {
public:
    map<int,int> m;
    void helper(vector<int> &nums, int i, int n, int x)
    {
        if(i>=n)
        {
            m[x]++;
            return;
        }
        helper(nums,i+1,n,x);
        helper(nums,i+1,n,x|nums[i]);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        helper(nums,0,nums.size(),0);
        int f=0;
        int a;
        for(auto it:m)
        {
            if(it.first>f)
            {
                f=it.first;
                a=it.second;
            }
        }
        return a;
    }
};