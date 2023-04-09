class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        map<int,vector<int>> mp;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }
        vector<long long> ans(n);
        for(auto it:mp)
        {
            long num = it.first;
            vector<int> indexes = it.second;
            long TotalSum = 0;
            for(auto it:indexes) TotalSum+=it;
            long PreSum = 0;
            for(long i=0;i<indexes.size();i++)
            {
                long ind = indexes[i];
                ans[ind] += (ind*i);
                ans[ind] -= (PreSum);
                ans[ind] -= (ind*(indexes.size()-i-1));
                ans[ind] += (TotalSum-PreSum-ind);
                PreSum += ind;
            }
        }
        return ans;
    }
};