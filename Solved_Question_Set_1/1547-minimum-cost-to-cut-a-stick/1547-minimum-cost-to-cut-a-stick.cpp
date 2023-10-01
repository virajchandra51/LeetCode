class Solution {
public:
    vector<vector<int>> dp;
    int helper(int i, int j, vector<int>& cuts)
    {
        if(j-i<=1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INT_MAX;
        for(int k=i+1;k<j;k++)
        {
            ans=min(ans,cuts[j]-cuts[i]+helper(i,k,cuts)+helper(k,j,cuts));
        }
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);        
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int c = cuts.size();
        dp.resize(c+1,vector<int>(c+1,-1));
        return helper(0,c-1,cuts);
    }
};