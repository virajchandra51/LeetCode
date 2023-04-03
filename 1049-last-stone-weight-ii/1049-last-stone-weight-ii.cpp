class Solution {
public:
    int total;
    int ways(vector<vector<long>> &dp, vector<int> &nums, int index, int val)
    {
        if(index==nums.size())
        {
            if(val<0) return 1e9; return val;
        }
        if(dp[val+total][index]!=-1) return dp[val+total][index];
        long add = ways(dp,nums,index+1,val+nums[index]);
        long sub = ways(dp,nums,index+1,val-nums[index]);
        return dp[val+total][index] = min(add,sub);
    }
    int lastStoneWeightII(vector<int>& nums) {
        int sum = 0;
        for(auto it:nums) sum+=it;
        total=sum;
        vector<vector<long>> dp(2*sum+1,vector<long>(nums.size()+1,-1));
        return ways(dp,nums,0,0);
    }
};