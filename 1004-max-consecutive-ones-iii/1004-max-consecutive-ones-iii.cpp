class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int c = 0;
        int ans = 0;
        int i = 0;
        int j = 0;
        int n = nums.size();
        while(j<n)
        {
            if(nums[j]==1)
            {
                ans=max(ans,j-i+1);
                j++;
            }
            else
            {
                if(c<k)
                {
                    c++;
                    ans=max(ans,j-i+1);
                    j++;
                }
                else
                {
                    while(c>=k && i<j && nums[i]!=0)
                    {
                        i++;
                    }
                    i++;
                    ans=max(ans,j-i+1);
                    j++;
                }
            }
        }
        return ans;
    }
};