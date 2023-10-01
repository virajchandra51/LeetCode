class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size()+1,false);
        int n = nums.size();
        dp[n] = true;
        for(int i=n-1;i>=1;i--)
        {
            for(int j=1;j<=nums[i-1];j++)
            {
                if(dp[j+i])
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        for(auto it:dp)
            cout<<it<<" ";
        cout<<endl;
        return dp[1];
    }
};