class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        long i = 0;
        int n = nums.size();
        long currsum = 0;
        for(long j=0;j<n;j++)
        {
            currsum+=nums[j];
            while((currsum*(j-i+1))>=k)
            {
                currsum-=nums[i];
                i++;
            }
            ans+=(j-i+1);
        }
        return ans;
    }
};