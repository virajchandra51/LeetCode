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
        for(int kk=0;kk<k;kk++)
        {
            if(kk>0 && sums[kk]>=sums[kk-1])continue;
            sums[kk] += c[i];
            helper(c,sums,k,i+1,n);
            sums[kk] -= c[i];
        }
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        sort(jobs.rbegin(),jobs.rend());
        vector<long long> sum(k,0);
        helper(jobs,sum,k,0,n);
        return (int)ans;
    }
};