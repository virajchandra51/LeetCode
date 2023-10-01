class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map<char,int> mp,m;
        for(auto it:s)
            mp[it]++;
        for(auto it:target)
            m[it]++;
        int c=INT_MAX;
        for(auto it:m)
        {
            if(mp.find(it.first)==mp.end())
                return 0;
            else
            {
                c=min(c,mp[it.first]/it.second);
            }
        }
        return c;
    }
};