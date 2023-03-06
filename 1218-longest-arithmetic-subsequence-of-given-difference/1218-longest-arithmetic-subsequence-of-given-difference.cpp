class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int,int> dp;
        for(auto it:arr)
        {
            if(dp.find(it-difference)==dp.end())
                dp[it]=1;
            else
                dp[it]=1+dp[it-difference];
        }
        int m = 1;
        for(auto it:dp)
            m=max(m,it.second);
        return m;
    }
};