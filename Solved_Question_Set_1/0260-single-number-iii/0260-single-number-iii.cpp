class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff = diff & ~(diff-1);
        vector<int> rets = {0, 0};
        for (int num : nums)
        {
            if ((num & diff) == 0)
                rets[0] ^= num;
            else
                rets[1] ^= num;
        }
        return rets;
    }
};