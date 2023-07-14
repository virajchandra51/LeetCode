class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        sort(nums.begin(),nums.end());
        map<int,pair<int,int>> m;
        for(auto it:nums)
        {
            if(m.find(it%space)==m.end())
                m[it%space] = {it,1};
            else m[it%space].second++;
        }
        int f = 0;
        int n = -1;
        for(auto it:m)
        {
            if(it.second.second>f || (it.second.second==f && it.second.first<n))
            {
                n=it.second.first;
                f=it.second.second;
            }
        }
        return n;
    }
};