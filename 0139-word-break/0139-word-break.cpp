class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        for(auto it:wordDict)
            st.insert(it);
        int n = s.size();
        vector<int> dp(n,0);
        for(int i=0;i<n;i++)
        {
            string a = "";
            for(int j=i;j>=0;j--)
            {
                a = s[j]+a;
                if(j==0)
                {
                    if(st.find(a)!=st.end())
                    {
                        dp[i] = 1;
                        break;
                    }
                }
                else
                {
                    if(st.find(a)!=st.end() && dp[j-1]==1)
                    {
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }
        return dp[n-1];
    }
};