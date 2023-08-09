class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int ans;
        if(nums[n-1]>nums[0]) return nums[0];
        if(n==1) return nums[0];
        while(l<=r)
        {
            int mid = (l+r)>>1;
            if(mid+1<n && nums[mid+1]<nums[mid])
            {
                ans=mid;
                break;
            }
            if(mid-1>=0 && nums[mid-1]>nums[mid])
            {
                ans=mid-1;
                break;
            }
            else
            {
                if(nums[mid]>nums[0]) l=mid+1;
                else r=mid-1;
            }
        }
        return nums[ans+1];
    }
};