class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,INT_MAX);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            int mi = INT_MAX;
            for(int j=i+1;j<=(min(n-1,i+nums[i]));j++)
            {
                mi=min(mi,dp[j]);
            }
            if(mi!=INT_MAX)
            dp[i] = mi+1;
        }
        for(auto it:dp)
            cout<<it<<" ";
        cout<<endl;
        return dp[0];
    }
};