class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int i = 0;
        int j = 0;
        int c = 0;
        int n = nums.size();
        while(j<n)
        {
            if(nums[j]==1)
            {
                j++;
                ans=max(ans,j-i-1);
            }
            else
            {
                if(c==0)
                {
                    c++;
                    j++;
                    ans=max(ans,j-i-1);
                }
                else
                {
                    while(i<j && nums[i]!=0)
                    {
                        i++;
                    }
                    i++;
                    ans=max(ans,j-i-1);
                    j++;
                }
            }
        }
        return ans;
    }
};