class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map<char,int> mp;
        for(auto i:words)
        {
            for(auto it:i)
                mp[it]++;
        }
        for(auto it:mp)
        {
            if(it.second%words.size()!=0)
                return false;
        }
        return true;
    }
};