class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int c=0;
        for(auto it:words)
        {
            if(s.substr(0,it.size())==it)
                c++;
        }
        return c;
    }
};