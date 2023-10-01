class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int c = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(__builtin_popcount(i)==k) c+=nums[i];
        }
        return c;
    }
};