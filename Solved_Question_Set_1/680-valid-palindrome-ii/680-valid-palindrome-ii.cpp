class Solution {
public:
    bool isP(string s)
    {
        for(int i=0;i<s.size()/2;i++)
        {
            if(s[i]!=s[s.size()-i-1])
                return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int f=0;
        for(int i=0;i<s.size()/2;i++)
        {
            if(s[i]!=s[s.size()-i-1])
            {
                return isP(s.substr(i+1,s.size()-i-1-i)) || isP(s.substr(i,s.size()-i-i-1));
            }
        }
        return true;
    }
};