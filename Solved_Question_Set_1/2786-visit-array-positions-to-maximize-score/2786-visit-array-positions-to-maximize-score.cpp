class Solution {
public:
    vector<vector<long long>> dp;
    long long helper(vector<int>& nums, int i, int state, int n, int x)
    {
        if(i>=n) return 0;
        long long pick = INT_MIN;
        long long not_pick = INT_MIN;
        if(dp[i][state]!=-1) return dp[i][state];
        if(i==0)
        {
            pick = nums[i]+helper(nums,i+1,state,n,x);
            return dp[i][state]=pick;
        }
        not_pick = helper(nums,i+1,state,n,x);
        pick = nums[i]+helper(nums,i+1,nums[i]%2,n,x);
        if((state==1 && nums[i]%2==0)  || (state==0 && nums[i]%2==1))
            pick-=x;
        return dp[i][state]=max(pick,not_pick);
    }
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        int state=0;
        if(nums[0]&1) state=1;
        dp.resize(n+1,vector<long long>(2,-1));
        return helper(nums,0,state,n,x);
    }
};