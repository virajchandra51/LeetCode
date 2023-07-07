class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>&v, int i, int n, int turn)
    {
        if(i>=n) return 0;
        if(dp[i][turn]!=-1) return dp[i][turn];
        if(turn)
        {
            int res = INT_MIN;
            res=max(res,v[i]+helper(v,i+1,n,0));
            if(i+1<n)
            res=max(res,v[i]+v[i+1]+helper(v,i+2,n,0));
            if(i+2<n)
            res=max(res,v[i]+v[i+1]+v[i+2]+helper(v,i+3,n,0));
            return dp[i][turn] = res;
        }
        int res = INT_MAX;
        res=min(res,-v[i]+helper(v,i+1,n,1));
        if(i+1<n)
        res=min(res,-v[i]-v[i+1]+helper(v,i+2,n,1));
        if(i+2<n)
        res=min(res,-v[i]-v[i+1]-v[i+2]+helper(v,i+3,n,1));
        return dp[i][turn] = res;
    }
    string stoneGameIII(vector<int>& v) {
        int n = v.size();
        dp.resize(n+1,vector<int>(2,-1));
        int ans = helper(v,0,n,1);
        if(ans>0) return "Alice";
        if(ans==0) return "Tie";
        return "Bob";
    }
};