class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while(nums.size()!=1)
        {
            vector<int> v; int f=0;
            for(int i=0;i<nums.size();i+=2)
            {
                if(f==0)
                {
                    v.push_back(min(nums[i],nums[i+1]));f=1;
                }
                else
                {
                    v.push_back(max(nums[i],nums[i+1]));f=0;
                }
            }
            nums=v;
        }
        return nums[0];
    }
};