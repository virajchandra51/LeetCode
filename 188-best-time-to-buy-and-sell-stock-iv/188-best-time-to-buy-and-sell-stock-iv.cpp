class Solution {
public:
    vector<vector<vector<int>>> dp;
    int r(vector<int> &prices,  int n, int k, int pos, bool bought)
    {
        if(k==0 || pos>=n)
            return 0;
        if(dp[bought][k][pos]!=-1)
        return dp[bought][k][pos];
        int sum = r(prices,n,k,pos+1,bought);
        if(bought)
            sum=max(sum,r(prices,n,k-1,pos+1,false)+prices[pos]);
        else
            sum=max(sum,r(prices,n,k,pos+1,true)-prices[pos]);
        dp[bought][k][pos] = sum;
        return sum;
    }
    int maxProfit(int k, vector<int>& prices) {
        dp.resize(2,vector<vector<int>>(k+1,vector<int>(prices.size(),-1)));
        return r(prices,prices.size(),k,0,false);
    }
};