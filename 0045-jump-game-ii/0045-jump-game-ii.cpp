class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int end = 0;
        int far = 0;
        int steps = 0;
        for(int i=0;i<n-1;i++)
        {
            far=max(far,nums[i]+i);
            if(i==end)
            {
                end=far;
                steps++;
            }
        }
        return steps;
    }
};