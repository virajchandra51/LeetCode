class Solution {
public:
    long long ans = INT_MAX;
    void helper(vector<int> &c, vector<long long> &sums, int k, int i, int n)
    {
        if(i>=n)
        {
            long long a = INT_MIN;
            for(auto it:sums) a=max(a,it);
            ans=min(a,ans);
            return;
        }
        for(int kk=1;kk<=k;kk++)
        {
            sums[kk-1] += c[i];
            helper(c,sums,k,i+1,n);
            sums[kk-1] -= c[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<long long> sum(k,0);
        helper(cookies,sum,k,0,n);
        return (int)ans;
    }
};