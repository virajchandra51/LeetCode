class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n,-1);
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            long t1 = (long)nums[i]-(long)target;
            long t2 = (long)nums[i]+(long)target;
            int j = i-1;
            int m = INT_MIN;
            while(j>=0)
            {
                if(nums[j]>=t1 && nums[j]<=t2 && dp[j]!=-1)
                    m=max(m,1+dp[j]);
                j--;
            }
            if(m!=INT_MIN)
            dp[i]=m;
        }
        return dp[n-1];
    }
};