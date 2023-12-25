class Solution {
public:
    int numDecodings(string s) {
        if(s.size()==0)
            return 0;
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1] = (s[0]=='0')?0:1;
        for(int i=2;i<=n;i++)
        {
            int f = stoi(s.substr(i-1,1));
            int ss = stoi(s.substr(i-2,2));
            if(f>=1 && f<=9)
                dp[i]+=dp[i-1];
            if(ss>=10 && ss<=26)
                dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};
