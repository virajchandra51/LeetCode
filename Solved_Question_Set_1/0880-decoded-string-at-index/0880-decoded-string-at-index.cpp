class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long curr = 0;
        for(auto it:s)
        {
            if(isdigit(it))
                curr*=(it-'0');
            else curr++;
        }
        for(int i = s.size()-1;i>=0;i--)
        {
            if(isdigit(s[i]))
            {
                curr/=(s[i]-'0');
                k%=curr;
            }
            else
            {
                if(k==0 || k==curr)
                {
                    string a = "";
                    a+=s[i];
                    return a;
                }
                curr--;
            }
        }
        return "viraj";
    }
};