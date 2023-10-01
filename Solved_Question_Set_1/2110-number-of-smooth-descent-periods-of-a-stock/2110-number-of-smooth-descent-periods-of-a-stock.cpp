class Solution {
    public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=0;
        long long curr=1, n=prices.size();
        for(int i=1;i<n;i++){
            if(prices[i]+1==prices[i-1])curr++;
            else{
                ans+=(curr*(curr+1))/2;
                curr=1;
            }
        }ans+=(curr*(curr+1))/2;
        return ans;
    }
};