class Solution {
public:
    string compressedString(string word) {
        string a = "";
        int c = 1;
        for(int i=1;i<word.size();i++)
        {
            if(word[i]!=word[i-1])
            {
                a+=to_string(c);
                a+=word[i-1];
                c=1;
            }
            else
            {
                if(c==9)
                {
                    a+="9";
                    a+=word[i-1];
                    c=1;
                }
                else c++;
            }
        }
        a+=to_string(c);
        a+=word[word.size()-1];
        return a;
    }
};