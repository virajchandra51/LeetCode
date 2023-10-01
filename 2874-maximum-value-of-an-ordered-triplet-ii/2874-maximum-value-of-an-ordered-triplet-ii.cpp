class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> premx(n),sufmx(n);
        premx[0]=nums[0];
        sufmx[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            sufmx[i] = max(sufmx[i+1],nums[i]*1LL);
        }
        for(int i=1;i<n;i++)
        {
            premx[i] = max(premx[i-1],nums[i]*1LL);
        }
        long long ans = 0;
        for(int i=1;i<n-1;i++)
        {
            long long a = premx[i-1];
            a-=nums[i];
            a*=(sufmx[i+1]);
            ans=max(ans,a);
        }
        return ans;
    }
};