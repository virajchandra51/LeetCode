class Solution {
public:
    vector<int> ans;
    void pre()
    {
        for(int i=1;i<=100;i++)
            ans.push_back(i*i);
        return;
    }
    int numSquares(int n) {
        pre();
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        if(n==1)
            return 1;
        for(int i=2;i<=n;i++)
        {
            int res=INT_MAX;
            for(int j=0;j<ans.size();j++)
            {
                if((i-ans[j])>=0)
                {
                    res = min(res,dp[i-ans[j]]+1);
                }
            }
            dp[i]=res;
        }
        for(auto it:dp)
            cout<<it<<" ";
        cout<<endl;
        return dp[n];
    }
};