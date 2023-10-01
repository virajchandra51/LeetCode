class Solution {
public:
    int check(vector<int>& nums, int n, int mid)
    {
        int c = 0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1]<=mid)
            {
                c++;
                i++;
            }
        }
        return c;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0;
        int r = nums[n-1]-nums[0];
        int ans;
        while(l<=r)
        {
            int mid = (l+r)>>1;
            if(check(nums,n,mid)>=p)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};