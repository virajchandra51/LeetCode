class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        auto it = max_element(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[nums.size()-1]<(2*nums[i]))
                return -1;
        }
    return (it-nums.begin());    
    }
};