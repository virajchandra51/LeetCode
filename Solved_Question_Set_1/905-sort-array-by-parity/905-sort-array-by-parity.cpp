class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&1)
                c++;
            else
                swap(nums[i-c],nums[i]);
        }
        return nums;
    }
};