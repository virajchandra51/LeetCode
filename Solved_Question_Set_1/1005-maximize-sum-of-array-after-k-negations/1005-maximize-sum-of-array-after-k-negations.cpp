class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size();i++){
            if(nums[i] < 0 && k > 0){
                nums[i] = -nums[i];
                k--;
            }
            else if(nums[i] >= 0 && k > 1){
                if(k %2 == 0) k = 0;
                else k = 1;
            }
        }
        int mn = INT_MAX;
        if(k == 1) {
            for(auto num: nums){
                mn = min (mn, num);
            }
        }
        mn =  mn != INT_MAX?mn: 0;
        
        return accumulate(nums.begin(), nums.end(), 0) - 2*mn;
    }
};