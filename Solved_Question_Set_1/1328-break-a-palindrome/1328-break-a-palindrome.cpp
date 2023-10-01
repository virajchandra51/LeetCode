class Solution {
public:
    string breakPalindrome(string s) {
        if(s.size()<2)
            return "";
        int f=0;
        for(int i=0;i<(s.size()/2);i++)
        {
            if(s[i]!='a')
            {
                s[i]='a';f=1;break;
            }
        }
        if(f==1)
            return s;
        return s.substr(0,s.size()-1)+'b';
    }
};