class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums)
            mp[it]++;
        for(auto it:mp)
        {
            if(it.second==(nums.size()/2))
                return it.first;
        }
        return 0;
    }
};