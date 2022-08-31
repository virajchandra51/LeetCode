class Solution {
public:
    string rz(string s)
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='0')
                return s.substr(i);
        }
        return "0";
    }
    bool isSumEqual(string ff, string ss, string t) {
        for(int i=0;i<ff.size();i++)
        {
            char c = (ff[i]-'a')+48;
            ff[i]=c;
        }
        for(int i=0;i<ss.size();i++)
        {
            char c = (ss[i]-'a')+48;
            ss[i]=c;
        }
        for(int i=0;i<t.size();i++)
        {
            char c = (t[i]-'a')+48;
            t[i]=c;
        }
        if(stoi(rz(ff))+stoi(rz(ss))==stoi(rz(t)))
            return true;
        return false;
    }
};