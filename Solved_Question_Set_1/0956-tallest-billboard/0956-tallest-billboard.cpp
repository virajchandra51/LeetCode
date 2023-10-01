class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& rods, int i, int n, int sum)
    {
        if(i>=n) 
        {
            if(sum==0) return 0;
            return -1e9;
        }
        if(dp[i][sum+5000]!=-1) return dp[i][sum+5000];
        int nottake = helper(rods,i+1,n,sum);
        int take1 = rods[i]+helper(rods,i+1,n,sum-rods[i]);
        int take2 = rods[i]+helper(rods,i+1,n,sum+rods[i]);
        return dp[i][sum+5000] = max({nottake,take1,take2});
    }
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int sum = 0;
        for(auto it:rods) sum+=it;
        dp.resize(n+1,vector<int>(sum+5001,-1));
        return helper(rods,0,n,0)/2;
    }
};