class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int sum=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
                ans.push_back(nums[i]);
            sum+=nums[i];
        }
        sum+=nums[nums.size()-1];
        ans.push_back(ans[0]+(nums.size()*(nums.size()+1)/2)-sum);
        return ans;
    }
};