class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans = -1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if((nums[i+1]-nums[i])==1)
            {
                int c = 2;
                for(int j=i+2;j<nums.size();j+=2)
                {
                    if(nums[j]==nums[i]) c++;
                    else break;
                    if(j+1<nums.size() && nums[j+1]==nums[i+1]) c++;
                    else break;
                }
                ans=max(ans,c);
            }
        }
        return ans;
    }
};