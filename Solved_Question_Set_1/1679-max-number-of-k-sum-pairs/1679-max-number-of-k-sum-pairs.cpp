class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int c = 0;
        int i = 0;
        int n = nums.size();
        int j = n-1;
        while(i<j)
        {
            if(nums[i]+nums[j]==k)
            {
                c++;
                i++;
                j--;
            }
            else if(nums[i]+nums[j]>k)
            {
                j--;
            }
            else i++;
        }
        return c;
    }
};