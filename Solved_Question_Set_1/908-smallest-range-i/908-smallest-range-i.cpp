class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(nums[nums.size()-1]-nums[0]>(2*k))
        {
            return nums[nums.size()-1]-k-nums[0]-k;
        }
        return 0;
    }
};