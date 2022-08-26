class Solution {
public:
    bool ch(string &s,string w){
        for(int i=0;i<s.size();i+=(w.size()))
        {
            if(s.substr(i,w.size())!=w)
                return false;
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        string w="";
        if(str1.size()<str2.size())
        {
            for(int i=1;i<=str1.size();i++)
            {
                if(ch(str2,str1.substr(0,i)) && ch(str1,str1.substr(0,i)))
                    w=str1.substr(0,i);
            }
        }
        else
        {
            for(int i=1;i<=str2.size();i++)
            {
                if(ch(str1,str2.substr(0,i)) && ch(str2,str2.substr(0,i)))
                    w=str2.substr(0,i);
            }
        }
        return w;
    }
};