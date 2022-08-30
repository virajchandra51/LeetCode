class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int i1=-1,i2=-1;
        int c=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
            {
                c++;
            }
        }
        if(c>2)
            return false;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
            {
                i1=i;break;
            }
        }
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i] && i!=i1)
            {
                i2=i;break;
            }
        }
        if(i1!=-1 && i2!=-1 && s1[i2]==s2[i1] && s1[i1]==s2[i2])
            return true;
        if(i1==-1 && i2==-1)
            return true;
        return false;
    }
};