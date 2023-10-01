class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int c=0;
        for(auto it:words)
        {
            if(it.substr(0,pref.size())==pref)
                c++;
        }
        return c;
    }
};