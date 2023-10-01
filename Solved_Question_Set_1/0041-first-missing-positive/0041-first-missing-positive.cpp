class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums)
        {
            if(it>0)
                mp[it]++;
        }
        int c=1;
        for(auto it:mp)
        {
            if(it.first==c) c++;
            else
                return c;
        }
        return c;
    }
};