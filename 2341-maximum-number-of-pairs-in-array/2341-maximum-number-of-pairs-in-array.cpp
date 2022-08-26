class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums)
            mp[it]++;
        int c=0,cc=0;
        for(auto it:mp)
        {
            if(it.second&1)
                cc++;
            c+=(it.second/2);
        }
        return {c,cc};
    }
};