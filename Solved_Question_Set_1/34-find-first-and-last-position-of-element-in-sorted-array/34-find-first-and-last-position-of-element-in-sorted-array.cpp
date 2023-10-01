class Solution {
public:
    int BS(vector<int>& nums, int l, int r, int t, bool f)
    {
        int ans=-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid]==t)
            {
                ans=mid;
                if(f)
                    r=mid-1;
                else
                    l=mid+1;
            }
            else if(nums[mid]<t)
                l=mid+1;
            else
                r=mid-1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int t) {
        vector<int> v(2);
        v[0] = BS(nums,0,nums.size()-1,t,true);
        v[1] = BS(nums,0,nums.size()-1,t,false);
        return v;
    }
};