class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans=0;
        int c=1;
        int shift=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1] && c<2)
                c++;
            else
            {
                if(nums[i]==nums[i-1])
                {
                    continue;
                }
                else
                {
                    ans+=c;
                    c=1;
                }
            }
        }
        ans+=c;
        int res=ans;
        c=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                if(c<2)
                    c++;
                else
                {
                    shift++;
                }
                nums[i-shift] = nums[i];
            }
            else
            {
                nums[i-shift] = nums[i];
                c=1;
            }
        }
        nums[nums.size()-1-shift] = nums[nums.size()-1];
        return res;
    }
};