class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int ans=0;
        for(int a=0;a<nums.size();a++)
        {
            for(int b=a+1;b<nums.size();b++)
            {
                for(int c=b+1;c<nums.size();c++)
                {
                    for(int d=c+1;d<nums.size();d++)
                    {
                        if(nums[a]+nums[b]+nums[c]==nums[d])
                            ans++;
                    }
                }
            }
        }
        return ans;
    }
    
};