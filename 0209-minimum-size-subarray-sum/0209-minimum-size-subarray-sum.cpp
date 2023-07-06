class Solution {
public:
    long id(vector<int>& a, int st, int n, int t)
    {
        int l = st;
        int r = n-1;
        long ans=-1;
        while(l<=r)
        {
            int m = (l+r)>>1;
            if(a[m]>=t)
            {
                ans=m;
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return ans;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        long ans = INT_MAX;
        int n = nums.size();
        vector<int> a(n);
        a[0]=nums[0];
        for(int i=1;i<n;i++) a[i]=a[i-1]+nums[i];
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                auto it = id(a,i,n,target);
                if(it==-1)
                    continue;
                else
                    ans=min(ans,it-i+1);
            }
            else
            {
                auto it = id(a,i,n,target+a[i-1]);
                if(it==-1)
                    continue;
                else
                    ans=min(ans,it-i+1);
            }
        }
        return ans==INT_MAX?0:ans;
    }
};