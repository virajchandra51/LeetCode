class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int c = 0;
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            c=0;
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                if(nums[j]<nums[i]) c++;
            }
            ans.push_back(c);
        }
        return ans;
    }
};