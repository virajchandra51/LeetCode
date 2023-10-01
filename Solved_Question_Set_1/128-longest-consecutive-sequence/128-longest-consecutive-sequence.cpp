class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int c=-1;
        int cc=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]!=nums[i])
            {
                if(nums[i+1]-nums[i]==1)
                cc++;
                else
                {
                    c=max(c,cc+1);
                    cc=0;
                }
            }
        }
        c=max(c,cc+1);
        return c;
    }
};