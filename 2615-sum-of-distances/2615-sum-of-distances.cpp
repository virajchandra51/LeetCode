class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        map<int,vector<long>> mp;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }
        vector<long long> ans(n);
        for(auto it:mp)
        {
            long num = it.first;
            vector<long> indexes = it.second;
            long TotalSum = 0;
            for(auto it:indexes) TotalSum+=it;
            long PreSum = 0;
            for(long i=0;i<indexes.size();i++)
            {
                ans[indexes[i]] = ((indexes[i]*i)-(PreSum))+(TotalSum-PreSum-indexes[i])-(indexes[i]*(indexes.size()-1-i));
                PreSum += indexes[i];
            }
        }
        return ans;
    }
};