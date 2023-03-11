class Solution {
public:
  //   4 9 25 64 169
  //   2 3 5 8 13
  //   1 2 3 4 5
  // 1 2 3 5 8 13
    long long int m = 1e9+7;
    int countHousePlacements(int n) {
        vector<long long int> dp(n+1,0);
        if(n==1) return 4;
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<=n;i++)
        dp[i]=(dp[i-1]%m+dp[i-2]%m)%m;
        long long int ans = dp[n]%m;
        ans*=dp[n];
        ans%=m;
        return (int)ans%m;
    }
};