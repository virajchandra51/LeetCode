class Solution {
public:
    bool detectCapitalUse(string word) {
        int f1=1,f2=1,f3=1;
        if(word[0]<'A' || word[0]>'Z')
            f3=0;
        if(f3)
        {
            if(word.size()==1)
                return true;
            for(int i=1;i<word.size();i++)
            {
                if(word[i]<'a' || word[i]>'z')
                {
                    f3=0;break;
                }
            }
            if(f3)
                return true;
        }
        for(int i=0;i<word.size();i++)
        {
            if(word[i]<'a' || word[i]>'z')
                {
                    f2=0;break;
                }
        }
        for(int i=0;i<word.size();i++)
        {
            if(word[i]<'A' || word[i]>'Z')
                {
                    f1=0;break;
                }
        }
        if(f1==0 && f2==0)
            return false;
        else
            return true;
    }
};