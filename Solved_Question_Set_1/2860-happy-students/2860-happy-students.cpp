class Solution {
public:
    int countWays(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(nums[0]>0) ans++;
        for(int i=0;i<n-1;i++)
        {
            if(i+1>nums[i] && i+1<nums[i+1]) ans++;
        }
        if(nums[n-1]<n) ans++;
        return ans;
    }
};
