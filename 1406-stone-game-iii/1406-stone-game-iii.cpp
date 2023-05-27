class Solution {
public:
    vector<int> dp;
    int helper(vector<int>& v, int i,int n)
    {
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = INT_MIN; int alice=0;
        for(int k=i;k<min(n,i+3);k++)
        {
            alice+=v[k];
         ans=max(ans,alice+min({helper(v,k+2,n),helper(v,k+3,n),helper(v,k+4,n)}));
        }
        return dp[i]=ans;
    }
    string stoneGameIII(vector<int>& v) {
        int n = v.size();
        dp.resize(n+1,-1);
        int aliceS = helper(v,0,n);
        int bobS = accumulate(v.begin(),v.end(),0) - aliceS;
        if(aliceS>bobS) return "Alice";
        else if(aliceS<bobS) return "Bob";
        return "Tie";
    }
};