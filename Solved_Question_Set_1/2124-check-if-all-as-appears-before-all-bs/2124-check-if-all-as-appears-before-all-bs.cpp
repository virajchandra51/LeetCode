class Solution {
public:
    bool checkString(string s) {
        int id = -1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='b')
            {
                id=i;break;
            }
        }
        if(id==-1)
            return true;
        for(int i=id;i<s.size();i++)
        {
            if(s[i]=='a')
                return false;
        }
        return true;
    }
};