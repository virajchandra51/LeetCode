class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int ans = 0;
        int f = INT_MAX;
        int c = 0;
        for(int i=0;i<nums.size();i++)
        {
            f&=nums[i];
            if(f==0)
            {
                ans++;
                c=1;
                if(i+1<nums.size()) f=nums[i+1];
            }
            else
            {
                continue;
            }
        }
        return max(ans,1);
    }
};