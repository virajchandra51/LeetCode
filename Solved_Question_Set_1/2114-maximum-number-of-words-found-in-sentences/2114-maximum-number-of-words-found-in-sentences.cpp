class Solution {
public:
    int wc(string s)
    {
        s+=" "; int c=0;
        string w="";
        for(auto it:s)
        {
            if(it!=' ')
                w+=it;
            else
            {
                c++;
                w="";
            }
        }
        return c;
    }
    int mostWordsFound(vector<string>& sentences) {
        int d=-1;
        for(auto it:sentences)
        {
            d=max(wc(it),d);
        }
        return d;
    }
};