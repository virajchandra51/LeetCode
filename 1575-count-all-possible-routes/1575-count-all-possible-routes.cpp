class Solution {
public:
    vector<vector<int>> dp;
    int m = 1e9+7;
    int helper(vector<int>& locations, int finish, int fuel, int curr, int n)
    {
        if(dp[curr][fuel]!=-1) return dp[curr][fuel];
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(i!=curr)
            {
                if(fuel-(abs(locations[i]-locations[curr]))>=0)
                    ans = (ans%m+helper(locations,finish,fuel-(abs(locations[i]-locations[curr])),i,n)%m)%m;
            }
        }
        if(curr==finish) return dp[curr][fuel]=1+ans;
        return dp[curr][fuel]=ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        dp.resize(n+1,vector<int>(fuel+1,-1));
        return helper(locations,finish,fuel,start,locations.size());
    }
    // 1 2 3 6 8 4 3
};