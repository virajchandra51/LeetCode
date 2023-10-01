class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> e(nums.size()/2),o(nums.size());
        int l=0,r=0;
        for(auto it:nums)
        {
            if(it&1)
                o[l++]=it;
            else
                e[r++]=it;
        }
        l=0,r=0;
        for(int i=0;i<nums.size();i+=2)
        {
            nums[i] = e[l++];
            nums[i+1] = o[r++];
        }
        return nums;
    }
};