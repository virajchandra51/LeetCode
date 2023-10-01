class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int t) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int ans = 0;
        while(i<n && j<n)
        {
            if(nums[i]%2==0 && nums[i]<=t)
            {
                j = i+1;
                while(j<n && nums[j]%2!=nums[j-1]%2 && nums[j]<=t) j++;
                ans = max(ans,j-i);
                i=j;
            }
            else
                i++;
        }
        return ans;
    }
};