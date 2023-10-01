class Solution {
public:
    bool checkZeroOnes(string s) {
        int lz=0,lo=0,cz=0,co=0;
        if(s[0]=='0')
            cz=1;
        else
            co=1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==s[i-1] && s[i]=='0')
                cz++;
            else if(s[i]==s[i-1] && s[i]=='1')
                co++;
            else if(s[i-1]=='0' && s[i]=='1')
            {
                lz=max(lz,cz);
                cz=0;
                co=1;
            }
            else
            {
                lo=max(lo,co);
                co=0;
                cz=1;
            }
        }
        if(s[s.size()-1]=='0')
            lz = max(lz,cz);
        else
            lo = max(lo,co);
        if(lo>lz)
            return true;
        else 
            return false;
    }
};