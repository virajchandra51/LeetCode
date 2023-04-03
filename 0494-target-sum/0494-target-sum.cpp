class Solution {
public:
//     1,1.  1,-1
// 2,2 2,0. 2,0 2,-2
// 3,3 3,1 3,1 3,-1 3,1 3,-1
    int total;
    int ways(vector<vector<long>> &dp, vector<int> &nums, int index, int target, int val)
    {
        if(index==nums.size() && val==target)
            return 1;
        else if(index==nums.size() && val!=target) return 0;
        if(dp[val+total][index]!=INT_MIN) return dp[val+total][index];
        long add = ways(dp,nums,index+1,target,val+nums[index]);
        long sub = ways(dp,nums,index+1,target,val-nums[index]);
        return dp[val+total][index] = add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto it:nums) sum+=it;
        if(sum<target) return 0;
        total=sum;
        vector<vector<long>> dp(2*sum+1,vector<long>(nums.size()+1,INT_MIN));
        return ways(dp,nums,0,target,0);
    }
};