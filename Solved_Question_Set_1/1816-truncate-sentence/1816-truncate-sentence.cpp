class Solution {
public:
    string truncateSentence(string s, int k) {
        string w="";
        string ans="";
        s+=" ";
        for(auto it:s)
        {
            if(it!=' ')
                w+=it;
            else
            {
                ans+=(w+" ");
                k--;
                if(k==0)
                    break;
                w="";
            }
        }
        return ans.substr(0,ans.size()-1);
    }
};