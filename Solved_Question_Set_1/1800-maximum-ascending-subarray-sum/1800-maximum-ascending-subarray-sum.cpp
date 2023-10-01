class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum=-1;
        int c=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
                c+=nums[i];
            else
            {
                sum=max(sum,c);
                c=nums[i];
            }
        }
        sum=max(sum,c);
        return sum;
    }
};