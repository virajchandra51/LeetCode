class Solution {
public:
    int BS(int ind, vector<vector<int>>& offers){
        int l = ind+1;
        int r = offers.size()-1;
        int ans = offers.size();
        while(l<=r){
            int mid = (l+r)>>1;
            int curr = offers[mid][0];
            if(offers[ind][1]<curr)
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
    vector<int> dp;
    int solve(int ind, vector<vector<int>>& offers){
        if(ind==offers.size())
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int take = offers[ind][2];
        int nottake = solve(ind+1, offers);
        int next = BS(ind, offers);
        take+=solve(next, offers);
        return dp[ind]=max(take, nottake);
    }
    
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        dp.resize(offers.size(), -1);
        return solve(0, offers);
    }
};