class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int i = 0;
        int j = 0;
        int c = 0;
        int n = nums.size();
        for(int j=0;j<n;j++)
        {
            if(nums[j]==1)
            {
                ans=max(ans,j-i);
            }
            else
            {
                if(c==0)
                {
                    c++;
                    ans=max(ans,j-i);
                }
                else
                {
                    while(i<j && nums[i]!=0)
                    {
                        i++;
                    }
                    i++;
                    ans=max(ans,j-i);
                }
            }
        }
        return ans;
    }
};