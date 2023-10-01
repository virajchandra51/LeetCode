class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z=0,o=0,s=0;
        for(auto it:nums)
        {
            if(it==0)
                z++;
            else if(it==1)
                o++;
            else
                s++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(z>0)
            {
                nums[i]=0;
                z--;
                continue;
            }
            else if(o>0)
            {
                nums[i]=1;
                o--;
                continue;
            }
            else 
            {
                nums[i]=2;
                s--;
                continue;
            }
        }
    }
};