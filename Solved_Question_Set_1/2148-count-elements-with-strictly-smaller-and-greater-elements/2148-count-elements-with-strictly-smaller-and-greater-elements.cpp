class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<=2)
            return 0;
        int c = nums.size()-2;
        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[0] || nums[i]==nums[nums.size()-1])
                c--;
        }
        return c;
    }
};