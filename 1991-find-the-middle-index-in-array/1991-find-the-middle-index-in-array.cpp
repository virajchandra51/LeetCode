class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
         int total = accumulate(nums.begin(), nums.end(), 0);
    int left_sum = 0;
    for(int i = 0; i<nums.size(); i++){
        int right_sum = total - left_sum - nums[i];
        if(right_sum == left_sum) return i;
        left_sum += nums[i]; 
    }
    return -1;
    }
};