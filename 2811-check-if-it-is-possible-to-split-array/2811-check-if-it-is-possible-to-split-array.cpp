class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if(n==1 || n==2) return true;
        int sum = nums[0]+nums[1];
        if(sum>=m) return true;
        for(int i=2;i<n;i++)
        {
            sum+=nums[i];
            sum-=nums[i-2];
            if(sum>=m) return true;
        }
        return false;
    }
};