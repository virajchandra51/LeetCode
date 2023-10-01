class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
                nums[i]*=-1;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
            nums[i]=pow(nums[i],2);
        return nums;
    }
};