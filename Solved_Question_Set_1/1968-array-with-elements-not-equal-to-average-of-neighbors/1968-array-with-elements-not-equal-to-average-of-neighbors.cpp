class Solution {
public:
    //0 2 6 7 9 10 11
    //0 6 2 9 7 11 10 
    
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()&1)
        {
            for(int i=1;i<nums.size();i+=2)
            {
                swap(nums[i],nums[i+1]);
            }
            return nums;
        }
        for(int i=0;i<nums.size();i+=2)
            swap(nums[i],nums[i+1]);
        return nums;
    }
};