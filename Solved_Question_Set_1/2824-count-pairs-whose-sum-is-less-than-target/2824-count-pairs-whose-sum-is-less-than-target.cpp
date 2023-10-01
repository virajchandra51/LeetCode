class Solution {
public:
    int countPairs(vector<int>& nums, int t) {
        int n = nums.size();
        int c = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]+nums[j]<t) c++;
            }
        }
        return c;
    }
};