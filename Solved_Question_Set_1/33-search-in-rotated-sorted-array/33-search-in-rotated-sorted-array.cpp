class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(nums[m]==target)
                return m;
            if(nums[l]==target)
                return l;
            if(nums[r]==target)
                return r;
            if(nums[l] < nums[m]){
                if(target > nums[l] && target < nums[m])
                    r = m-1;
                else 
                    l = m+1;
            } else if(nums[r] > nums[m]){
                if(target > nums[m] && target < nums[r])
                    l = m+1;
                else 
                    r = m-1;
            } else return -1;
        }
        return -1;
    }
};