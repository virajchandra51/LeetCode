class Solution {
public:
    string mergeAlternately(string s, string t) {
        string a="";
        int i=0,j=0;
        while(i<s.size() && j<t.size())
        {
            a+=s[i];
            i++;
            a+=t[j];
            j++;
        }
        while(i<s.size())
        {
            a+=s[i];
            i++;
        }
        while(j<t.size())
        {
            a+=t[j];
            j++;
        }
        return a;
    }
};