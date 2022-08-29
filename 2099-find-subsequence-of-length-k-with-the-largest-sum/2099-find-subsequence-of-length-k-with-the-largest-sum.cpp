class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> mp;
        for(int i=0;i<nums.size();i++)
            mp.push_back({nums[i],i});
        sort(mp.begin(),mp.end());
        vector<int> v;
        int i = mp.size()-1;
        while(i>=0 && k>0)
        {
            v.push_back(mp[i].second);
            i--;k--;
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(auto it:v)
        ans.push_back(nums[it]);
        return ans;
    }
};