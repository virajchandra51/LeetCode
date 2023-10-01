class Solution {
public:
    vector<vector<int>> dp;
    int r(vector<int> &prices,  int n, int pos, bool bought)
    {
        if(pos>=n)
            return 0;
        if(dp[bought][pos]!=-1)
        return dp[bought][pos];
        int sum = r(prices,n,pos+1,bought);
        if(bought)
            sum=max(sum,r(prices,n,pos+2,false)+prices[pos]);
        else
            sum=max(sum,r(prices,n,pos+1,true)-prices[pos]);
        dp[bought][pos] = sum;
        return sum;
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(2,vector<int>(prices.size(),-1));
        return r(prices,prices.size(),0,false);
    }
};