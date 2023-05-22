class Solution {
public:
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
                auto it = lower_bound(a.begin()+i,a.end(),target)-a.begin();
                if(it==n)
                    continue;
                else
                    ans=min(ans,it-i+1);
            }
            else
            {
                auto it = lower_bound(a.begin()+i,a.end(),target+a[i-1])-a.begin();
                if(it==n)
                    continue;
                else
                    ans=min(ans,it-i+1);
            }
        }
        // 1 3 6 10 15
        // 1 5 9
        return ans==INT_MAX?0:ans;
    }
};