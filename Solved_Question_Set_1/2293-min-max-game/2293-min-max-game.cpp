class Solution {
public:
    int minMaxGame(vector<int>& nums) {
         ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        vector<int> newNums(n/2);
        for(int i = 0; i < n/2; i++) newNums[i] = (i%2)? newNums[i] = max(nums[2*i], nums[2*i+1]):min(nums[2*i], nums[2*i+1]);
        int ans = minMaxGame(newNums);
        return ans;
    }
};