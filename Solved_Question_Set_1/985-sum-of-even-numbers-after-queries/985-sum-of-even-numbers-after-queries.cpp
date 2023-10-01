class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries)       {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(!(nums[i]&1))
                sum+=nums[i];
        }
        vector<int> ans;
        for(auto it:queries)
        {
            int val = it[0];
            int i = it[1];
            if(!(nums[i]&1))
                sum-=(nums[i]);
            nums[i]+=val;
            if(!(nums[i]&1))
                sum+=(nums[i]);            
            ans.push_back(sum);
        }
        return ans;
    }
};