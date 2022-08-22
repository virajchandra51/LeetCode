class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size(), ok = 1;
        // check for monotone increasing
        for (int i = 1 ; i < n; i++) ok &= nums[i - 1] <= nums[i];
        // if it is monotone increasing, return true
        if (ok) return true;
        // reset ok
        ok = 1;
        // check for monotone decreasing
        for (int i = n - 2; i >= 0; i--) ok &= nums[i] >= nums[i + 1];
        // return the answer
        return ok;
    }
};