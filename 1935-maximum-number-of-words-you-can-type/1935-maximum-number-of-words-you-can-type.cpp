class Solution {
public:
    int canBeTypedWords(string text, string b) {
        text+=" ";
        string w=""; int c=0;
        for(auto it:text)
        {
            if(it!=' ')
                w+=it;
            else
            {
                int f=1;
                for(int i=0;i<b.size();i++)
                {
                    if(w.find(b[i])!=std::string::npos)
                    {
                        f=0;break;
                    }
                }
                if(f)
                    c++;
                w="";
            }
        }
        return c;
    }
};