class Solution {
public:
    string greatestLetter(string s) {
        map<char,int> mp;
        for(auto it:s)
            mp[it]=1;
        string ans="";
        for(auto it:mp)
        {
            if(mp.find((char)(it.first-32))!=mp.end() && it.first>='a' && it.first<='z')
                ans=(it.first-32);
        }
        return ans;
    }
};