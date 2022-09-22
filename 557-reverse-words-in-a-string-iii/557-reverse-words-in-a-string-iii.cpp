class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string w="";
        s+=' ';
        for(auto it:s)
        {
            if(it!=' ')
                w+=it;
            else
            {
                reverse(w.begin(),w.end());
                ans+=w;
                ans+=" ";
                w="";
            }
        }
        return ans.substr(0,ans.size()-1);
    }
};