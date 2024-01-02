class Solution {
public:
    bool check(map<int,int> &m)
    {
        for(auto it:m)
        {
            if(it.second>0) return true;
        }
        return false;
    }
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> mp;
        for(int i=1;i<=200;i++)
            mp[i]=0;
        for(auto it:nums) mp[it]++;
        vector<vector<int>> v;
        while(check(mp))
        {
            vector<int> a;
            for(auto &it:mp)
            {
                if(it.second>0)
                {
                    it.second--;
                    a.push_back(it.first);
                }
            }
            v.push_back(a);
        }
        return v;
    }
};